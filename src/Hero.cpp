/***********************************************************************
 * File: Hero.cpp
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-05-28
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-05-28
 * Description: A Hero class that can move and attack
************************************************************************/
#include "Hero.h"
#include "Map.h"

/**
 * Intent: default constructor
 * Pre: none
 * Post: a Hero object is created
 */
Hero::Hero()
{
	this->sPos.x = 0;
	this->sPos.y = 0;
	this->sLevel = 1;
	this->sCurrentExp = 0;
	this->sMaxExp = 15;
	this->sIcon = 'H';
	this->hp = 100;
};

/**
 * Intent: constructor with position
 * Pre: x is postive integer, y is postive integer, level is postive integer, maxExp is postive integer, currentExp is postive integer, icon is a char, hp is postive integer, maxHP is postive integer
 * Post: a Hero object is created
 */
Hero::Hero(int x, int y, int level, int maxExp, int currentExp, char icon, int hp, int maxHP)
{
	this->sPos.x = x;
	this->sPos.y = y;
	this->sLevel = level;
	this->sCurrentExp = currentExp;
	this->sMaxExp = maxExp;
	this->sIcon = icon;
	this->hp = hp;
	this->sMaxHP = maxHP;
};

/**
 * Intent: constructor with position
 * Pre: pos is a Position object, level is postive integer, maxExp is postive integer, currentExp is postive integer, icon is a char, hp is postive integer, maxHP is postive integer
 * Post: a Hero object is created
 */
Hero::Hero(Position& pos, int level, int maxExp, int currentExp, char icon, int hp, int maxHP)
{
	this->sPos = pos;
	this->sLevel = level;
	this->sCurrentExp = currentExp;
	this->sMaxExp = maxExp;
	this->sIcon = icon;
	this->hp = hp;
	this->sMaxHP = maxHP;
};

/**
 * Intent: Set position
 * Pre: pos is a Position object
 * Post: none
 */
void Hero::setPos(Position pos)
{
	this->sPos = pos;
};

/**
 * Intent: Set position
 * Pre: x is postive integer, y is postive integer
 * Post: none
 */
void Hero::setPos(int x, int y)
{
	this->sPos.x = x;
	this->sPos.y = y;
};

/**
 * Intent: Set Icon
 * Pre: icon is a char
 * Post: none
 */
void Hero::setIcon(char& icon)
{
	this->sIcon = icon;
};

/**
 * Intent: Set level
 * Pre: level is postive integer
 * Post:
 */
void Hero::setLevel(int level)
{
	this->sLevel = level;
};

/**
 * Intent: Set exp
 * Pre: exp is postive integer
 * Post: none
 */
void Hero::setExp(int exp)
{
	this->sCurrentExp = exp;
};

/**
 * Intent: Set max exp
 * Pre: maxexp is postive integer
 * Post: none
 */
void Hero::setMaxExp(int points)
{
	this->sMaxExp = points;
};

/**
 * Intent: Get position
 * Pre: none
 * Post: return a Position object
 */
Position Hero::getPos(void)
{
	return this->sPos;
};

/**
 * Intent: Get icon
 * Pre: none
 * Post: return a char
 */
char Hero::getIcon(void)
{
	return this->sIcon;
};

/**
 * Intent: Get level
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getLevel(void)
{
	return this->sLevel;
};

/**
 * Intent: Get exp
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getExp(void)
{
	return this->sCurrentExp;
};

/**
 * Intent: Get max exp
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getMaxExp(void)
{
	return this->sMaxExp;
};

/**
 * Intent: Get current hp
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getHP(void) const
{
	return this->hp;
};

/**
 * Intent: Set current hp
 * Pre: hp is postive integer
 * Post: none
 */
void Hero::setHP(int hp)
{
	this->hp = hp;
};

/**
 * Intent: Get attack value
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getAttack(void) const
{
	return this->sAttack;
};

/**
 * Intent: Set attack value
 * Pre: attack is postive integer
 * Post: none
 */
void Hero::setAttack(int attack)
{
	this->sAttack = attack;
};

/**
 * Intent: Increase hero's exp
 * Pre: points is postive integer
 * Post: none
 */
void Hero::gainEXP(int points)
{
	int number = points;
	while (number > 0)
	{
		if (sCurrentExp + number >= sMaxExp)
		{ // level up
			number -= (sMaxExp - sCurrentExp);
			sCurrentExp = 0;
			sMaxExp = (int)((float)sMaxExp * 1.2f);
			sLevel++;
			sMaxHP += 10;
		}
		else
		{
			sCurrentExp += number;
			number = 0;
		}
	}
};

/**
 * Intent: Reduce hero's exp
 * Pre: points is postive integer
 * Post: none
 */
void Hero::reduceEXP(int points)
{
	int number = points;
	// if level is 1, exp can't be reduced
	if (sLevel == 1)
		return;

	while (number > 0)
	{
		if (sCurrentExp - number < 0)
		{ // level down
			number -= sCurrentExp;
			sCurrentExp = sMaxExp;
			sMaxExp = (int)((float)sMaxExp / 1.2f);
			sLevel--;
			sMaxHP -= 10;
		}
		else
		{
			sCurrentExp -= number;
			number = 0;
		}
	}
}

/**
 * Intent: Reduce hero's hp
 * Pre: points is postive integer
 * Post: none
 */
void Hero::damage(int points)
{
	hp = hp - points;
	if (hp < 0)
		hp = 0;
};

/**
 * Intent: Increase hero's hp
 * Pre: points is postive integer
 * Post: none
 */
void Hero::heal(int points)
{
	hp = hp + points;
	if (hp > sMaxHP)
		hp = sMaxHP;
};

/**
 * Intent: Move hero
 * Pre: delta is a Position object
 * Post: none
 */
void Hero::move(Position delta)
{
	// Compute the next position
	Position next = this->sPos + delta;

	if (isPositionValid(next))
		this->sPos = next;
	else
	{
		std::cout << "Invalid location\n";
	}
}

/**
 * Intent: Get MaxHP
 * Pre: none
 * Post: return a postive integer
 */
int Hero::getMaxHP(void) const
{
	return this->sMaxHP;
};

/**
 * Intent: Set MaxHP
 * Pre: maxHP is postive integer
 * Post: none
 */
void Hero::setMaxHP(int maxHP)
{
	this->sMaxHP = maxHP;
};

/**
 * Intent: Add MaxHP
 * Pre: points is postive integer
 * Post: none
 */
void Hero::addMaxHP(int points)
{
	this->sMaxHP += points;
};
