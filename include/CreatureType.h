/***********************************************************************
 * File: CreatureType.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Describe here
************************************************************************/
#pragma once

#include "Icon.h"
#include <string>

using namespace std;

enum CreatureType
{
	CREATURE_DAMAGE,
	CREATURE_HEAL,
	CREATURE,
	CREATURE_SEE_HERO
};

// function
string creatureTypeString(int type);



