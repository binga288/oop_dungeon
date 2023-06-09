﻿/***********************************************************************
 * File: CreatureHealth.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-22
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-22
 * Description: A Creature class that can heal the hero
************************************************************************/
#pragma once
#include "Creature.h"

// class
class CreatureHeal : public Creature
{
public:
	// constructor
	CreatureHeal();
	CreatureHeal(int power, int HP);
	CreatureHeal(Position position, int power, int HP);
	CreatureHeal(int x, int y, int power, int HP);
	// destructor
	~CreatureHeal();

	void update(Hero& hero) override;
};
