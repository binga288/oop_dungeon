/***********************************************************************
 * File: GameMenu.h
 * Author: TING-AN LIAO (B11130237)
 * Create Date: 2023-06-11
 * Editor: TING-AN LIAO (B11130237)
 * Update Date: 2023-06-11
 * Description: Header file of GameMenu class
************************************************************************/

#include "GameDifficulty.h"
#include "GameMode.h"

class GameMenu {
public:
	void displayModeMenu();
	GameMode getModeChoice();
	void displayDifficultyMenu();
	GameDifficulty getDifficultyChoice();
};
