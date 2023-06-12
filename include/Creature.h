/***********************************************************************
 * File: Creature.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Creature class that can damage the hero
************************************************************************/
#pragma once
#include "Position.h"
#include "Hero.h"
#include <string>

class Creature {//creature class 
protected:
	char sIcon = 'C';			// Creature icon
	int creatureType;			// Creature type
	int HP;
private:
	Position	sPos;			// Creature position
	int power;
public:
	// Default constructor
	Creature(void);
	Creature(int x, int y, int power, int HP);
	Creature(Position pos, int power, int HP);

	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);
	// Get position
	Position getPos(void) const;

	// Set icon
	void setIcon(char icon);
	// Get Icon
	char getIcon(void) const;

	// Set power
	void setPower(int power);
	// Get power
	int getPower(void) const;
	// Set HP
	void setHP(int HP);
	// Get HP
	int getHP(void) const;

	// is dead
	bool isDead(void) const;

	virtual void update(Hero& hero);
};