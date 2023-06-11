/***********************************************************************
 * File: BrightSightPotion.h
 * Author: ¹ù§Ê¦w (B11130237)
 * Create Date: 2023-06-11
 * Editor: ¹ù§Ê¦w (B11130237)
 * Update Date: 2023-06-11
 * Description: Header file of BrightSightPotion class
 ***********************************************************************/
 
#pragma once
#include "Item.h"

class BrightSightPotion : public Item
{
public:
	// constructor
	BrightSightPotion();
	BrightSightPotion(int x, int y);
	BrightSightPotion(const Position& pos);

	// destructor
	~BrightSightPotion();

	// update hero
	void update(Hero& hero) override;
};
