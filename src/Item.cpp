/**
 * File: Item.cpp
 * Author: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Update Date: 2023-05-28
 * Description: Item class
 */

#include "Item.h"
#include "Icon.h"

 /**
  * Intent: Constructor with no parameter
  * Pre: None
  * Post: A Item object
  */
Item::Item(void)
{
	pos = Position(1, 1);
	icon = ICON_ITEM;
	power = 0;
}

/**
 * Intent: Constructor with position
 * Pre: position is a Position object
 * Post: A Item object
 */
Item::Item(const Position& pos)
{
	this->pos = pos;
	icon = ICON_ITEM;
	power = 0;
}

/**
 * Intent: Constructor with position object, icon and power
 * Pre: position is a Position object, icon is a character, power is an integer
 * Post: A Item object
 */
Item::Item(const Position& pos, char icon, int power)
{
	this->pos = pos;
	this->icon = icon;
	this->power = power;
}

/**
 * Intent: Constructor with x, y, icon and power
 * Pre: x and y are integers, icon is a character, power is an integer
 * Post: A Item object
 */
Item::Item(int x, int y, char icon, int power)
{
	this->pos = Position(x, y);
	this->icon = icon;
	this->power = power;
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
Item::~Item() {}

/**
 * Intent: Get icon
 * Pre: None
 * Post: Return icon
 */
char Item::getIcon()
{
	return icon;
}

/**
 * Intent: Get position
 * Pre: None
 * Post: Return position
 */
Position Item::getPos()
{
	return pos;
}

/**
 * Intent: Get power
 * Pre: None
 * Post: Return power
 */
int Item::getPower()
{
	return power;
}

/**
 * Intent: Set Position
 * Pre: pos is a Position object
 * Post: None
 */
void Item::setPos(const Position& pos)
{
	this->pos = pos;
}

/**
 * Intent: Update the item
 * Pre: hero is a Hero object
 * Post: None
 */
void Item::update(Hero& hero)
{

}
