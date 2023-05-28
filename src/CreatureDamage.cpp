/**
 * File: CreatureDamage.cpp
 * Author: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (b11115001@gapps.ntust.edu.tw)
 * Update Date: 2023-05-28
 * Description: A Creature class that can damage the hero
 */
#include "CreatureDamage.h"
#include "CreatureType.h"
#include "Map.h"
#include "Icon.h"

using namespace std;

/**
 * Intent: Default constructor
 * Pre: None
 * Post: A CreatureDamage object
 */
CreatureDamage::CreatureDamage(void) : Creature(1, 1, 5)
{
	this->setIcon(ICON_CREATURE_DAMAGE);
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: Constructor with power
 * Pre: power is an integer and is positive
 * Post: A CreatureDamage object
 */
CreatureDamage::CreatureDamage(int power) : Creature(1, 1, power)
{
	this->setIcon(ICON_CREATURE_DAMAGE);
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: Constructor with position and power
 * Pre: power is an integer and is positive, position is a Position object
 * Post: A CreatureDamage object
 */
CreatureDamage::CreatureDamage(int x, int y, int power) : Creature(x, y, power)
{
	this->setIcon(ICON_CREATURE_DAMAGE);
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: Constructor with x, y and power
 * Pre: power is an integer and is positive, x and y are integers
 * Post: A CreatureDamage object
 */
CreatureDamage::CreatureDamage(Position pos, int power) : Creature(pos, power)
{
	this->setIcon(ICON_CREATURE_DAMAGE);
	this->creatureType = CreatureType::CREATURE_DAMAGE;
}

/**
 * Intent: Destructor
 * Pre: None
 * Post: None
 */
CreatureDamage::~CreatureDamage(void)
{
}

/**
 * Intent: Reduce the hero's health if the creature can touch the hero
 * Pre: hero is a Hero object
 * Post: None
 */
void CreatureDamage::update(Hero& hero)
{
	Position hPos = hero.getPos();
	Position dir, sPos = this->getPos();
	int power = this->getPower();

	int creatureType = this->creatureType;
	string type = creatureTypeString(creatureType);

	if (canSee(sPos, hPos, dir))
	{
		cout << type << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sIcon = ICON_CREATURE_SEE_HERO;
	}
	else
	{
		cout << type << " didn't find the Hero\n";
		this->sIcon = ICON_CREATURE_DAMAGE;
	}

	if (!(hPos != sPos))
	{
		hero.damage(power);
	}
}
