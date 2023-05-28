/***********************************************************************
 * File: main.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Item class
************************************************************************/
#pragma once
#include "Hero.h"
#include "Position.h"

using namespace std;

// Forward declaration
class Hero;

// Item class
class Item
{
protected:
	char icon;
	Position pos;
	int power;
public:
	Item(void);
	Item(const Position& pos);
	Item(const Position& pos, char icon, int power);
	Item(int x,int y, char icon, int power);

	~Item();

	// Get icon
	char getIcon();

	// Get position
	Position getPos();

	// Get power
	int getPower();

	// Set position
	void setPos(const Position& pos);

	// Update hero
	virtual void update(Hero& hero);
};
