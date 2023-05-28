/***********************************************************************
 * File: Trigger.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Trigger class that can increase the EXP of hero
 ************************************************************************/
#pragma once
#include "Item.h"

class Hero;

//************************************************************
// Trigger Class
//************************************************************
class Trigger : public Item
{
public:
	// 	consturctor
	Trigger(void);
	Trigger(int x, int y);
	Trigger(const Position& pos);

	// destructor
	~Trigger();

	// update hero
	void update(Hero& hero) override;
};
