/***********************************************************************
 * File: Trigger.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Implementation for Trigger
************************************************************************/
#include "Trigger.h"
#include "Icon.h"

/**
 * Intent: Constructor with no parameter
 * Pre: None
 * Post: A Trigger object
 */
Trigger::Trigger(void)
{
	this->pos = Position(1, 1);
	this->icon = ICON_TRIGGER;
	this->power = 10;
}

/**
 * Intent: Constructor with x and y
 * Pre: x and y are integers
 * Post: A Trigger object
 */
Trigger::Trigger(int x, int y)
{
	this->pos = Position(x, y);
	this->icon = ICON_TRIGGER;
	this->power = 10;
}

/**
 * Intent: Constructor with position
 * Pre: position is a Position object
 * Post: A Trigger object
 */
Trigger::Trigger(const Position& pos)
{
	this->pos = pos;
	this->icon = ICON_TRIGGER;
	this->power = 10;
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Trigger::~Trigger() {}

/**
 * Intent: Update hero when hero is on the same position as trigger and gain EXP
 * Pre: Hero class
 * Post: None
 */
void Trigger::update(Hero& hero)
{
	Position pos = this->getPos();
	int power = this->getPower();

	if (hero.getPos().x == pos.x && hero.getPos().y == pos.y)
	{
		hero.gainEXP(power);
	}
}