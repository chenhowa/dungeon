/******************************************************
Function Collection Name: 	Input.
Author:			Howard Chen
Date:			1/21/2017
Description:	A collection of functions that take and
					validate input for int, double, std::string.
************************************************8******/



#ifndef HC_INPUT_HPP
#define HC_INPUT_HPP

#include <string>
#include <iostream>

struct inputFun
{
	
	/*
	Description:	Gets an input from input stream and validates it.
	Arguments:		Integer of starting range (included), integer at ending range(included), input stream.
	Precondition:	None.
	Postcondition:	Returns an int representing user input.
					In particular, cin must have entered something that can be read as an integer
					that COULD NOT be interpreted as a floating point number.
	*/
	static int getAnInt(int start, int end, std::istream &in);
	
	/*
	Description: 	Gets int input from input stream, and validates it. Has default value
					if too many attempts.
	Arguments: 		default integer, minimum value, maximum value, input stream.
	Returns an integer.
	Precondition: 	None.
	Postcondition: 	User had 5 attempts to enter a valid integer in the
					acceptable range.
					If all those were invalid, then the default value
					'token' is returned.
	*/
	static int getInt(int token, int start, int end, std::istream &in);
	

	/*
	Description:	gets double input from the input stream. With type validation.
					for a maximum of five attempts.
	Arguments:		default value, minimum value, maximum value, input stream.
	Precondition:	None.
	Postcondition:	If the user enters a double in the valid range, that double is returned.
					If five incorrect attempts, the default value is returned.
	*/
	static double getDouble(double token, double start, double end, std::istream &in);

	/*
	Description:	Gets a string input from the input stream. With type validation.
	Arguments:		default value, input stream/
	Precondition:	Each input is terminated by a newline.
	Postcondition:	Returns string if a valid one is read.
					Otherwise returns the default string.
	*/
	static std::string getString(std::string token, std::istream &in);



};
#endif