/***********************************************************************
 * File: CreatureType.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: Describe here
************************************************************************/

#include "CreatureType.h"
#include "Icon.h"
#include <sstream>

using namespace std;
/**
 * Intent: Get creature type
 * Pre: none
 * Post: return a string
 */
string creatureTypeString(int type)
{
	ostringstream oss;

	switch (type)
	{
	case CreatureType::CREATURE_DAMAGE:
		oss << "Damage Creature(" << ICON_CREATURE_DAMAGE << ')';
		break;
	case CreatureType::CREATURE_HEAL:
		oss << "Heal Creature(" << ICON_CREATURE_HEAL << ')';
		break;
	default:
		oss << "Creature(" << ICON_CREATURE << ')';
		break;
	}

	return oss.str();
}
