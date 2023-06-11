/***********************************************************************
 * File: BrightSightPotion.cpp
 * Author: ¹ù§Ê¦w (B11130237)
 * Create Date: 2023-06-11
 * Editor: ¹ù§Ê¦w (B11130237)
 * Update Date: 2023-06-11
 * Description: Implementation of BrightSightPotion class
 ***********************************************************************/
 
#include "BrightSightPotion.h"
#include "Icon.h"

 /**
  * Intent: Constructor with no parameter
  * Pre: None
  * Post: A BrightSightPotion object
  */
BrightSightPotion::BrightSightPotion(): Item()
{
	this->icon = ICON_BIGHT_SIGHT_POTION;
}

/**
 * Intent: Constructor with x and y
 * Pre: x and y are integers
 * Post: A BrightSightPotion object
 */
BrightSightPotion::BrightSightPotion(int x, int y): Item(Position(x, y))
{
	this->icon = 'B';
}

/**
 * Intent: Constructor with position
 * Pre: position is a Position object
 * Post: A BrightSightPotion object
 */
BrightSightPotion::BrightSightPotion(const Position& pos): Item(pos)
{
	this->icon = 'B';
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
BrightSightPotion::~BrightSightPotion() {}

/**
 * Intent: Update hero when hero is on the same position as trigger and change hero's bright sight
 * * Pre: Hero class
 * * Post: None
 * */
void BrightSightPotion::update(Hero& hero)
{
	Position pos = this->getPos();
	if (hero.getPos().x == pos.x && hero.getPos().y == pos.y)
	{
		hero.setBrightSight(true);
		hero.setBrightSightRemain(10);
	}
}
