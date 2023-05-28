/***********************************************************************
 * File: Map.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Definition for functions about map
************************************************************************/
#pragma once

#include "Hero.h"
#include "Creature.h"
#include "Trigger.h"
#include "Position.h"
#include <vector>

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& pos);

// clip algroithm
float clip(float n, float minimun, float maximum);

// Check whether two position is close enough，利用 call-by-referce 將計算得到的方向回傳
bool canSee(Position cPos, Position hPos, Position& dir);

// 初始化版面
void setupBoard(int rowN, int colN);
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

void saveMap();
void loadMap();


void InitGame(void);