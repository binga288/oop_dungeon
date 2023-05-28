/***********************************************************************
 * File: HeartCrystal.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Item class that can increase the max HP of hero and heal hero
************************************************************************/
#pragma once
#include "Item.h"

class Hero;

class HeartCrystal : public Item
{
public:
	// 	consturctor
	HeartCrystal();
	HeartCrystal(int x, int y);
	HeartCrystal(const Position& pos);

	// destructor
	~HeartCrystal();

	// update hero
	void update(Hero& hero) override;
};
