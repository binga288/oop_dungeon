/***********************************************************************
 * File: GameData.cpp
 * Author: ���ʦw (B11130237)
 * Create Date: 2023-06-11
 * Editor: ���ʦw (B11130237)
 * Update Date: 2023-06-11
 * Description: 
 * Some description.
 ***********************************************************************/

#include "GameData.h"

GameData& GameData::getInstance() 
{
    static GameData instance;
    return instance;
}

GameData::GameData() 
{
}
