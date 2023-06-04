/***********************************************************************
 * File: Creature.cpp	
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-22
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-22
 * Description: Implementation for Creature
************************************************************************/
#include "Creature.h"
#include "Map.h"
#include "Icon.h"
#include "CreatureType.h"
#include <string>

using namespace std;

/**
 * Intent: default constructor
 * Pre: none
 * Post: a Creature object is created
 */
Creature::Creature(void)
{
	this->sPos.x = 1;
	this->sPos.y = 1;
	this->sIcon = 'C';
	this->power = 5;
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: constructor with position
 * Pre: x is postive integer, y is postive integer, power is postive integer
 * Post: a Creature object is created
 */
Creature::Creature(int x, int y, int power)
{
	this->sPos.x = x;
	this->sPos.y = y;
	this->sIcon = 'C';
	this->power = power;
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: constructor with position
 * Pre: pos is a Position object, power is postive integer
 * Post: a Creature object is created
 */
Creature::Creature(Position pos, int power)
{
	this->sPos = pos;
	this->sIcon = 'C';
	this->power = power;
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: Set position
 * Pre: pos is a Position object
 * Post: none
 */
void Creature::setPos(Position pos)
{
	this->sPos = pos;
}

/**
 * Intent: Set position
 * Pre: x is postive integer, y is postive integer
 * Post: none
 */
void Creature::setPos(int x, int y)
{
	this->sPos.x = x;
	this->sPos.y = y;
}

/**
 * Intent: Get position
 * Pre: none
 * Post: return a Position object
 */
Position Creature::getPos(void) const
{
	return this->sPos;
}

/**
 * Intent: Get position
 * Pre: none
 * Post: return a Position object
 */
void Creature::setIcon(char icon)
{
	this->sIcon = icon;
}

/**
 * Intent: Get position
 * Pre: none
 * Post: return a Position object
 */
char Creature::getIcon(void) const
{
	return this->sIcon;
}

/**
 * Intent: Set power
 * Pre: power is postive integer
 * Post: none
 */
void Creature::setPower(int power)
{
	this->power = power;
}

/**
 * Intent: Get power
 * Pre: none
 * Post: return a postive integer
 */
int Creature::getPower(void) const
{
	return this->power;
}

/**
 * Intent: Update the creature
 * Pre: hero is a Hero object
 * Post: none
 */
void Creature::update(Hero& hero)
{
	Position hPos = hero.getPos();

	int creatureType = this->creatureType;
	string type = creatureTypeString(creatureType);

	Position dir;
	if (canSee(this->sPos, hPos, dir))
	{
		cout << type << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sIcon = '!';
	}
	else
	{
		cout << type << " didn't find the Hero\n";
		this->sIcon = ICON_CREATURE;
	}

	if (!(hPos != sPos))
	{
		hero.damage(power);
	}
}
