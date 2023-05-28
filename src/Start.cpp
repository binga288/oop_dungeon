/***********************************************************************
 * File: Start.cpp
 * Author: BING-JIA TAN (B11115001) and TING-AN LIAO (B11130237)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001) and TING-AN LIAO (B11130237)
 * Update Date: 2023-05-28
 * Description: Implementation for Start
************************************************************************/
#include "Start.h"
#include "Hero.h"
#include "Trigger.h"
#include "Creature.h"
#include "CreatureHeal.h"
#include "CreatureDamage.h"
#include "HeartCrystal.h"
#include "Move.h"
#include "Map.h"
#include "Icon.h"
#include <vector>

Hero	 gHero;
// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

int GWIDTH = -1;
int GHEIGHT = -1;
const int MIN_SIZE = 4;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char** gBoard;

const int MIN_CHUNK = 3;
vector<Item*> gItems;
vector<Creature*> gCreatures;

const double gTimeLog = 0.033;

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	ESave = 6,
	ELoad = 7,
	INVALID,
};

// ******************************************************************
//
// * 初始化遊戲
//==================================================================
void InitGame(void)
{
	while (true)
	{
		std::cout << "Enter Width: ";
		std::cin >> GWIDTH;
		std::cout << "Enter Height: ";
		std::cin >> GHEIGHT;
		system("CLS");

		if (GHEIGHT < MIN_SIZE || GWIDTH < MIN_SIZE)
			std::cout << "Illegal, both has to be larger than " << MIN_SIZE << std::endl;
		else
			break;
	}

	// Setup a clear dungeon
	setupBoard(GHEIGHT, GWIDTH);

	// Draw the bord and information
	draw();
	drawInfo();

	RunGame();
}

//******************************************************************
//
// * 開始遊戲
//==================================================================
void RunGame(void)
{
	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[ValidInput::INVALID];
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		gKeyState[i] = false;
	}

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Run the game loop
	while (!gKeyState[ValidInput::EESC])
	{
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog)
		{
			update(gKeyState);
			draw();
			drawInfo();
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();

		if (gKeyState[ValidInput::ESave])
		{
			saveMap();
			gKeyState[ValidInput::ESave] = false;
		}
		else if (gKeyState[ValidInput::ELoad])
		{
			loadMap();
			gKeyState[ValidInput::ELoad] = false;
		}
	}
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	Position delta;

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW])
	{
		delta -= Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::ES])
	{
		delta += Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA])
	{
		delta -= Position(1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED])
	{
		delta += Position(1, 0);
		hasInput = true;
	}
	else
	{
		bool allInvalid = true;
		for (int i = 0; i < ValidInput::INVALID; i++)
		{
			if (key[i])
			{
				allInvalid = false;
				break;
			}
		}
		if (allInvalid)
			std::cout << "invalid input\n";
	}

	if (hasInput)
	{
		gHero.move(delta);
	}

	// Manipulate update of two triggers using while loop

	for (int i = 0; i < gItems.size(); i++)
	{
		gItems[i]->update(gHero);
	}

	for (int i = 0; i < gCreatures.size(); i++)
	{
		gCreatures[i]->update(gHero);
	}
	draw();
	drawInfo();
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	char input = _getch();
	switch (input)
	{
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	case '1':
		key[ValidInput::ESave] = true;
		break;
	case '2':
		key[ValidInput::ELoad] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position& dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do {
		// spot the target position
		if (cPos + dir * count == hPos) {
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

//******************************************************************
//
// * 利用 Recursive 產生迷宮
//==================================================================
void createMazeWithRecursive(char** board, int xStart, int yStart, int width, int height)
{
	if (width < 5 || height < 5) return;

	int xDiv = xStart + rand() % (width - 4) + 2;
	int yDiv = yStart + rand() % (height - 4) + 2;

	for (int i = 0; i < height; i++)
		if (i != yDiv) board[yStart + i][xDiv] = GWALL;
	for (int i = 0; i < width; i++)
		if (i != xDiv) board[yDiv][xStart + i] = GWALL;

	int doors[4] = { yStart + 1, yStart + height - 2, xStart + 1, xStart + width - 2 };

	if (yDiv - yStart - 1 > 0)
		doors[0] = yStart + rand() % (yDiv - yStart - 1) + 1;
	if (yStart + height - yDiv - 3 > 0)
		doors[1] = yDiv + 1 + rand() % (yStart + height - yDiv - 3);
	if (xDiv - xStart - 1 > 0)
		doors[2] = xStart + rand() % (xDiv - xStart - 1) + 1;
	if (xStart + width - xDiv - 3 > 0)
		doors[3] = xDiv + 1 + rand() % (xStart + width - xDiv - 3);

	board[doors[0]][xDiv] = ' '; // Up
	board[doors[1]][xDiv] = ' '; // Down
	board[yDiv][doors[2]] = ' '; // Left
	board[yDiv][doors[3]] = ' '; // Right

	createMazeWithRecursive(board, xStart, yStart, xDiv - xStart, yDiv - yStart); // top left
	createMazeWithRecursive(board, xDiv + 1, yStart, width - xDiv + xStart - 1, yDiv - yStart); // top right
	createMazeWithRecursive(board, xStart, yDiv + 1, xDiv - xStart, height - yDiv + yStart - 1); // bottom left
	createMazeWithRecursive(board, xDiv + 1, yDiv + 1, width - xDiv + xStart - 1, height - yDiv + yStart - 1); // bottom right
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard(int rowN, int colN)
//==================================================================
{
	// Allocate & init game board using 2d dynamic array

	gBoard = new char* [rowN];
	for (int i = 0; i < rowN; i++)
	{
		gBoard[i] = new char[colN];
		for (int j = 0; j < colN; j++)
		{
			if (i == 0 || i == rowN - 1 || j == 0 || j == colN - 1)
				gBoard[i][j] = GWALL;
			else
				gBoard[i][j] = GNOTHING;
		}
	}

	/*Please implement your code here*/
	createMazeWithRecursive(gBoard, 1, 1, colN - 2, rowN - 2);
	/************************************************************************/

	// Setup for (random) position of all elements and implementation of game board using 2d dynamic array
	// Elements has to be randomly generated within canvas

	std::vector<std::vector<bool>> validFlags(GHEIGHT);
	for (int i = 0; i < GHEIGHT; i++)
	{
		validFlags[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++)
		{
			validFlags[i][j] = gBoard[i][j] == GWALL ? false : true;
		}
	}

	auto getRandomPos = [&rowN, &colN]()
	{
		return Position((int)(rand() % colN), (int)(rand() % rowN));
	};

	auto getValidRandomPos = [&validFlags, &getRandomPos]()
	{
		while (true)
		{
			Position pos = getRandomPos();
			if (validFlags[pos.y][pos.x])
			{
				return pos;
			}
		}
	};

	Position hPos = getValidRandomPos();
	validFlags[hPos.y][hPos.x] = false;
	gHero.setPos(hPos);

	CreatureHeal* gCreatureHeal = new CreatureHeal();
	Position chPos = getValidRandomPos();
	validFlags[chPos.y][chPos.x] = false;
	gCreatureHeal->setPos(chPos);
	gCreatures.push_back(gCreatureHeal);

	CreatureDamage* gCreatureDamage = new CreatureDamage();
	Position cdPos = getValidRandomPos();
	validFlags[cdPos.y][cdPos.x] = false;
	gCreatureDamage->setPos(cdPos);
	gCreatures.push_back(gCreatureDamage);


	Trigger* trigger = new Trigger();
	Position tPos = getValidRandomPos();
	validFlags[tPos.y][tPos.x] = false;
	trigger->setPos(tPos);
	gItems.push_back(trigger);

	HeartCrystal* heartCrystal = new HeartCrystal();
	Position hcPos = getValidRandomPos();
	validFlags[hcPos.y][hcPos.x] = false;
	heartCrystal->setPos(hcPos);
	gItems.push_back(heartCrystal);
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	// Setup and implementation of drawing board using 2d vector

	std::vector<std::vector<char>> drawBoard(GHEIGHT);

	for (int i = 0; i < GHEIGHT; i++)
	{
		drawBoard[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++)
		{
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Draw two triggers using for loop on drawBoard

	for (int i = 0; i < gItems.size(); i++)
	{
		Position t = gItems[i]->getPos();
		drawBoard[t.y][t.x] = gItems[i]->getIcon();
	}

	// Draw all creatures using for loop on drawBoard
	for (int i = 0; i < gCreatures.size(); i++)
	{
		Position c = gCreatures[i]->getPos();
		drawBoard[c.y][c.x] = gCreatures[i]->getIcon();
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	std::cout << "The hero is level " << gHero.getLevel() << "(" << gHero.getExp() << "/" << gHero.getMaxExp() << " to level up)" << std::endl;
	std::cout << "The hero has " << gHero.getHP() << " hp" << std::endl;
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Every time you step on a Item " << ICON_TRIGGER << ", the hero gets 10 exp." << std::endl;
	std::cout << "Every time you step on a Item " << ICON_HEART_CRYSTAL << ", the hero gets 20 max hp and heal 6 hp." << std::endl;
	std::cout << "(ESC) Exit (1) Save (2) Load" << std::endl;
}

//******************************************************************
//
// * Save the map status
//==================================================================
void saveMap() {
	// Save dungen to file
	system("CLS");
	std::cout << "Input file name for saving or Exit to leave saving." << std::endl;
	std::cout << "Input: ";
	std::string input;
	std::cin >> input;
	if (input.compare("Exit") == 0)
		return;

	std::ofstream oStream(input + ".txt");
	oStream << GWIDTH << " " << GHEIGHT << std::endl;

	for (int i = 0; i < GHEIGHT; i++)
	{
		for (int j = 0; j < GWIDTH; j++)
		{
			oStream << gBoard[i][j];
		}
		oStream << std::endl;
	}
	oStream << std::endl;

	oStream << gHero.getPos() << " " << gHero.getHP() << " " << gHero.getLevel() << " " << gHero.getExp() << " " << gHero.getMaxExp() << std::endl;
	oStream << gCreatures.size() << std::endl;
	for (int i = 0; i < gCreatures.size(); i++)
	{
		oStream << gCreatures[i]->getPos() << std::endl;
	}

	oStream << gItems.size() << std::endl;
	for (int i = 0; i < gItems.size(); i++)
	{
		oStream << gItems[i]->getPos() << std::endl;
	}

	oStream.close();
}

//******************************************************************
//
// * Load the map status
//==================================================================
void loadMap() {
	// Load from file and reset the dungen
	system("CLS");
	std::cout << "Input file name for loading or Exit to leave loading." << std::endl;
	std::cout << "Input: ";
	std::string input;
	std::cin >> input;
	if (input.compare("Exit") == 0)
		return;

	std::ifstream iStream(input + ".txt");
	if (!iStream.is_open())
		return;

	// reset dungen
	for (int i = 0; i < GHEIGHT; i++)
	{
		delete[] gBoard[i];
	}
	delete[] gBoard;

	for (int i = 0; i < gItems.size(); i++)
		delete gItems[i];
	gItems.clear();

	iStream >> GWIDTH >> GHEIGHT;

	char _c;
	iStream.get(_c);

	gBoard = new char* [GHEIGHT];
	for (int i = 0; i < GHEIGHT; i++)
	{
		gBoard[i] = new char[GWIDTH];
		for (int j = 0; j < GWIDTH; j++)
		{
			iStream.get(gBoard[i][j]);
		}
		iStream.get(_c);
	}

	Position pos;
	int hp, level, exp, maxExp;
	iStream >> pos >> hp >> level >> exp >> maxExp;

	gHero.setPos(pos);
	gHero.setHP(hp);
	gHero.setLevel(level);
	gHero.setExp(exp);
	gHero.setMaxExp(maxExp);

	int creatureN;
	iStream >> creatureN;
	for (int i = 0; i < creatureN; i++) {
		iStream >> pos;
		Creature* creature = new Creature();
		creature->setPos(pos);
		gCreatures.push_back(creature);
	}

	int triggerN;
	iStream >> triggerN;
	for (int i = 0; i < triggerN; i++) {
		iStream >> pos;
		Trigger* trigger = new Trigger();
		trigger->setPos(pos);
		gItems.push_back(trigger);
	}

	iStream.close();
}