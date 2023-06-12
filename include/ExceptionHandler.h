/***********************************************************************
 * File: ExceptionHandler.h
 * Author: BING-JIA TAN (B11115001)
 * Create Date: 2023-06-04
 * Editor: BING-JIA TAN (B11115001)
 * Update Date: 2023-06-04
 * Description: Exception Handler
************************************************************************/
#pragma once

#include <exception>

// Invalid Location
class InvalidLocation : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid location";
	}
};;

// Invalid Input
class InvalidInput : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid input";
	}
};

// Game Over
class GameOver : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Game over";
	}
};;

// Win
class Win : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "You Win!! You killed everyone!!";
	}
};
