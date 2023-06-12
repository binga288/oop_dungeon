/***********************************************************************
 * File: CreatureHeal.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-22
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-22
 * Description: Implementation for CreatureHeal
************************************************************************/

#include "CreatureHeal.h"
#include "Map.h"
#include "Icon.h"
#include "CreatureType.h"

using namespace std;

/**
 * Intent: Constructor with no parameter
 * Pre: None
 * Post: A CreatureHeal object
 */
CreatureHeal::CreatureHeal() : Creature(1, 1, 10, 10)
{
	this->setIcon(ICON_CREATURE_HEAL);
	this->creatureType = CreatureType::CREATURE_HEAL;
}

/**
 * Intent: Constructor with power
 * Pre: power is an integer and is positive
 * Post: A CreatureHeal object
 */
CreatureHeal::CreatureHeal(int power, int HP) : Creature(1, 1, power, HP)
{
	this->setIcon(ICON_CREATURE_HEAL);
	this->creatureType = CreatureType::CREATURE_HEAL;
}

/**
 * Intent: Constructor with position and power
 * Pre: power is an integer and is positive, position is a Position object
 * Post: A CreatureHeal object
 */
CreatureHeal::CreatureHeal(Position pos, int power, int HP) : Creature(pos, power, HP)
{
	this->setIcon(ICON_CREATURE_HEAL);
	this->creatureType = CreatureType::CREATURE_HEAL;
}

/**
 * Intent: Constructor with x, y and power
 * Pre: power is an integer and is positive, x and y are integers
 * Post: A CreatureHeal object
 */
CreatureHeal::CreatureHeal(int x, int y, int power, int HP) : Creature(x, y, power, HP) {
	this->setIcon(ICON_CREATURE_HEAL);
	this->creatureType = CreatureType::CREATURE_HEAL;
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
CreatureHeal::~CreatureHeal()
{
}

// get the type of creature
//CreatureType CreatureHeal::getType() const {
//	return CreatureType::HEAL;
//}

/**
 * Intent: Heal the hero and reduce the hero's exp
 * Pre: hero is a Hero object
 * Post: None
 */
void CreatureHeal::update(Hero& hero) {

	Position hPos = hero.getPos();
	Position dir, sPos = this->getPos();
	int power = this->getPower();

	int creatureType = this->creatureType;
	string type = creatureTypeString(creatureType);

	if (canSee(sPos, hPos, dir))
	{
		cout << type << " has find the Hero in the(" << dir.x << ", " << dir.y << ") direction\n";
		this->sIcon = ICON_CREATURE_SEE_HERO;
	}
	else {
		cout << type << " didn't find the Hero\n";
		this->sIcon = ICON_CREATURE_HEAL;
	}

	if (!(hPos != sPos)) {
		hero.heal(power);
		hero.reduceEXP(power);
		this->HP -= hero.getAttack();
	}
}


