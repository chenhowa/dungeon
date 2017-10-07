/******************************************************
Function Collection Name: 	Input.
Author:			Howard Chen
Date:			1/21/2017
Description:	A collection of functions that take and
					validate input for int, double, std::string.
************************************************8******/


#include "input.hpp"
#include <iostream>
#include <sstream>

/*
Description:	Gets an input from input stream and validates it.
Arguments:		Integer of starting range (included), integer at ending range(included), input stream.
Precondition:	None.
Postcondition:	Returns an int representing user input.
				In particular, cin must have entered something that can be read as an integer
				that COULD NOT be interpreted as a floating point number.
*/
int inputFun::getAnInt(int start, int end, std::istream &in)
{
	//Reset the input stream.
	in.clear();
	
	//Create string and input string stream for
	//processing the input.
	std::string inputString;
	std::istringstream processStream;
	int input = -3000;

	
	//while the input attempt was invalid (not an integer) continue trying to
	//get input.
	bool invalid = true;
	while(invalid)
	{
		//Read input in as a striing.
		in >> inputString;
		
		//Initialize the input string stream, and
		//check to see if the input string has a decimal point.
		processStream.str(inputString);
		int decimal_point = inputString.find('.');
		processStream >> input;
		
		//If any input reads failed, if the input had a decimal point, or if
		//the input was out of range, print an error message. One less attempt
		//remaining.
		if(in.fail() || processStream.fail() || decimal_point != -1 || input > end || input < start)
		{
			std::cout << "Please enter a valid integer between " << start
				<< " and " << end << " inclusive:" << std::endl;
		}
		
		//Else the input was good. Keep it, and use it.
		else
		{
			
			invalid = false;
		}
		
		//Reset input streams for next read (if necessary).
		in.clear();
		in.ignore(1000,'\n');
		processStream.clear();
	}
	
	//Notify console that the input was received, and valid.
	//std::cout << "Input Received" << std::endl;
	
	return input;
}


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
int inputFun::getInt(int token, int start, int end, std::istream &in)
{
	
	//Initialize attempts, reset the input stream.
	in.clear();
	int attempts = 0;
	
	//Create string and input string stream for
	//processing the input.
	std::string inputString;
	std::istringstream processStream;
	int input = -3000;

	
	//while the input attempt was invalid (not an integer)
	//and attempts are less than five, continue trying to
	//get input.
	bool invalid = true;
	while(attempts < 5 && invalid)
	{
		//Read input in as a striing.
		in >> inputString;
		
		//Initialize the input string stream, and
		//check to see if the input string has a decimal point.
		processStream.str(inputString);
		int decimal_point = inputString.find('.');
		processStream >> input;
		
		//If any input reads failed, if the input had a decimal point, or if
		//the input was out of range, print an error message. One less attempt
		//remaining.
		if(in.fail() || processStream.fail() || decimal_point != -1 || input > end || input < start)
		{
			attempts++;
			if(attempts != 5)
			{
				std::cout << "Please enter a valid integer between " << start
					<< " and " << end << " inclusive:" << std::endl;
			}
		}
		
		//Else the input was good. Keep it, and use it.
		else
		{
			
			invalid = false;
		}
		
		//Reset input streams for next read (if necessary).
		in.clear();
		in.ignore(1000,'\n');
		processStream.clear();
	}
	if(attempts == 5)
	{
		std::cout << "Too many bad attempts" << std::endl;
		std::cout << "A default value of " << token << " will be used" << std::endl;
		input = token;
	}
	std::cout << "Input Received" << std::endl;
	
	return input;
}

/*
Description:	gets double input from the input stream. With type validation.
				for a maximum of five attempts.
Arguments:		default value, minimum value, maximum value, input stream.
Precondition:	None.
Postcondition:	If the user enters a double in the valid range, that double is returned.
				If five incorrect attempts, the default value is returned.
*/
double inputFun::getDouble(double token, double start, double end, std::istream &in)
{
	double input = -5000.0;
	
	//initialize attempts, clear standard input,
	in.clear();
	int attempts = 0;
	
	//while the input attempt was invalid (not an integer)
	//prompt user for a new input. Once 5 attempts are reached,
	//just use the default token value.
	bool invalid = true;
	while(attempts < 5 && invalid)
	{
		in >> input;
		if(!in || input > end || input < start)
		{
			attempts++;
			if(attempts != 5)
			{
				std::cout << "Please enter a valid double between " << start
					<< " and " << end << " inclusive:" << std::endl;
			}
		}
		else
		{
			invalid = false;
		}
		in.clear();
		in.ignore(1000,'\n');
	}
	if(attempts == 5)
	{
		std::cout << "Too many bad attempts" << std::endl;
		std::cout << "A default value of " << token << " will be used" << std::endl;
		input = token;
	}
	std::cout << "Input Received" << std::endl;
	
	return input;
}

/*
Description:	Gets a string input from the input stream. With type validation.
Arguments:		default value, input stream/
Precondition:	Each input is terminated by a newline.
Postcondition:	Returns string if a valid one is read.
				Otherwise returns the default string.
*/
std::string inputFun::getString(std::string token, std::istream &in)
{
	std::string input = "";
	
	//Reset the input stream, initialize the attempts.
	in.clear();
	int attempts = 0;
	
	//While less than five attempts and last input was invalid,
	//keep reading input in and validating it.
	bool invalid = true;
	while(attempts < 5 && invalid)
	{
		//Reads one line of input at a time.
		std::getline(in, input);
		if(in.fail())
		{
			attempts++;
			if(attempts != 5)
			{
				std::cout << "Please enter a valid string." << " Seriously, what the  heck "
						"did you enter?" << std::endl;
			}
		}
		else
		{
			invalid = false;
		}
		in.clear();
		//in.ignore(1000,'\n'); //This is probably unnecessary.
	}
	if(attempts == 5)
	{
		std::cout << "Too many bad attempts" << std::endl;
		std::cout << "A default value of " << token << " will be used" << std::endl;
		input = token;
	}
	std::cout << "Input Received" << std::endl;
	
	return input;
}
