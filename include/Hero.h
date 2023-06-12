/***********************************************************************
 * File: Hero.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Hero class that can move and attack
 ************************************************************************/
#pragma once
#include <string>
#include "Position.h"

 //************************************************************
 // Hero Class, only has requirement part for example
 //************************************************************

class Hero
{

private:
	Position sPos;	  // Hero location
	char sIcon = 'H'; // Hero icon
	int hp;
	int sMaxHP = 100;
	int sLevel = 1;	  // Level
	int sMaxExp;	  // Level update experience
	int sCurrentExp;  // current exp hero has
	int sAttack = 10; // Attack
	bool hasBrightSight = false; // Bright sight
	int brightSightRemain = 0; // Bright sight remain round
	Position faceTo = { 0,0 }; // Face to direction
public:
	// Default constructor
	Hero();
	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100, int maxHP = 100);

	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100, int maxHP = 100);

	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);

	// Set icon
	void setIcon(char& icon);

	// Set level
	void setLevel(int level);

	// Set exp
	void setExp(int exp);

	// Set MaxExp
	void setMaxExp(int points);

	// Get position
	Position getPos(void);

	// Get Icon
	char getIcon(void);

	// Get level
	int getLevel(void);

	// Get Exp
	int getExp(void);

	// Get Max
	int getMaxExp(void);

	// Get HP
	int getHP() const;
	// Set HP
	void setHP(int hp);

	// Get MaxHP
	int getMaxHP() const;
	// Set MaxHP
	void setMaxHP(int maxHP);
	// Add MaxHP
	void addMaxHP(int points);

	// Get Attack
	int getAttack(void) const;
	// Set Attack
	void setAttack(int attack);

	// Get BrightSight
	bool getBrightSight(void) const;
	// Set BrightSight
	void setBrightSight(bool brightSight);

	// Get BrightSightRemain
	int getBrightSightRemain(void) const;
	// Set BrightSightRemain
	void setBrightSightRemain(int brightSightRemain);

	// Incrementally move the elements
	void move(Position delta);

	// Calculate Gain of EXP
	void gainEXP(int points);
	// Reduce EXP
	void reduceEXP(int points);

	void damage(int points);
	void heal(int points);
};
