/***********************************************************************
 * File: CreatureDamage.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Creature class that can damage the hero
************************************************************************/
#pragma once
#include "Creature.h"

class CreatureDamage : public Creature {
public:
	// Default constructor
	CreatureDamage(void);
	CreatureDamage(int power);
	CreatureDamage(int x, int y, int power);
	CreatureDamage(Position pos, int power);
	// destructor
	~CreatureDamage(void);

	void update(Hero& hero) override;
};
