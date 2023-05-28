/***********************************************************************
 * File: HeartCrystal.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Implementation for HeartCrystal
************************************************************************/

#include "HeartCrystal.h"
#include "Hero.h"
#include "Icon.h"

/**
 * Intent: Constructor with no parameter
 * Pre: None
 * Post: A HeartCrystal object
 */
HeartCrystal::HeartCrystal() : Item(1, 1, ICON_HEART_CRYSTAL, 20)
{
}

/**
 * Intent: Constructor with x and y
 * Pre: x and y are integers
 * Post: A HeartCrystal object
 */
HeartCrystal::HeartCrystal(int x, int y) : Item(x, y, ICON_HEART_CRYSTAL, 20)
{
}

/**
 * Intent: Constructor with position
 * Pre: position is a Position object
 * Post: A HeartCrystal object
 */
HeartCrystal::HeartCrystal(const Position& pos) : Item(pos, ICON_HEART_CRYSTAL, 20)
{
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
HeartCrystal::~HeartCrystal()
{
}

/**
 * Intent: Increase the max HP of hero and heal hero
 * Pre: hero is a Hero object
 * Post: None
 */
void HeartCrystal::update(Hero& hero)
{
	Position pos = this->getPos();
	int power = this->getPower();

	if (hero.getPos().x == pos.x && hero.getPos().y == pos.y)
	{
		hero.addMaxHP(power);
		hero.heal(power / 3);
	}
}
