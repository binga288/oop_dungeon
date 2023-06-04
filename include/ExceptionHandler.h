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

// Invaild Location
class InvaildLocation : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invaild location";
	}
};;

// Invaild Input
class InvaildInput : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invaild input";
	}
};
