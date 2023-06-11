/***********************************************************************
 * File: GameData.h
 * Author: ¹ù§Ê¦w (B11130237)
 * Create Date: 2023-06-11
 * Editor: ¹ù§Ê¦w (B11130237)
 * Update Date: 2023-06-11
 * Description: Header file of GameData class
 ***********************************************************************/
 
#pragma once
#include "GameDifficulty.h"
#include "GameMode.h"

class GameData 
{
public:
    static GameData& getInstance();

    GameData(GameData const&) = delete;
    void operator=(GameData const&) = delete;

    GameDifficulty difficulty;
    GameMode mode;

private:
    GameData();
};
