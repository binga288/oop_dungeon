/***********************************************************************
 * File: GameMenu.cpp
 * Author: 廖廷安 (B11130237)
 * Create Date: 2023-06-11
 * Editor: 廖廷安 (B11130237)
 * Update Date: 2023-06-11
 * Description: Implementation of GameMenu class
 ***********************************************************************/

#include"GameMenu.h"
#include<iostream>

using namespace std;

void GameMenu::displayModeMenu()
{
	std::cout << "1.新遊戲\n";
	std::cout << "2.加載遊戲\n";
	std::cout << "3.離開遊戲\n";
}

GameMode GameMenu::getModeChoice()
{
	system("CLS");
	this->displayModeMenu();
	int choice;
	std::cout << "請選擇模式：";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		return GameMode::NEW_GAME;
	case 2:
		return GameMode::LOAD_GAME;
	case 3:
		return GameMode::EXIT_GAME;
	default:
		return this->getModeChoice();
	}
}

void GameMenu::displayDifficultyMenu()
{
	std::cout << "1.簡單\n";
	std::cout << "2.普通\n";
	std::cout << "3.困難\n";
}

GameDifficulty GameMenu::getDifficultyChoice()
{
	system("CLS");
	this->displayDifficultyMenu();
	int choice;
	std::cout << "請選擇難度：";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		return GameDifficulty::EASY;
	case 2:
		return GameDifficulty::NORMAL;
	case 3:
		return GameDifficulty::HARD;
	default:
		return this->getDifficultyChoice();
	}
}
