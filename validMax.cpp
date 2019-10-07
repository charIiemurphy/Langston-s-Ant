/*********************************************************
 * Name: Charles Kusk
 * Date: April 10, 2019
 * Description: Defines validMax function
**********************************************************/

#include <iostream>
#include <cctype>	// isdigit()
#include <string>	// std::string, std::stoi
#include <stdlib.h>	// strtol()
#include "validMax.hpp"

int validMax(int maxValue)
{		
	std::string input;
	bool charPresent = false;       // Boolean that says if string has a non integer
	long inputAsLong;		// Needed to use long toi use strtol
	char *ptr;			// Needed this pointer for strtol, not sure why
	while(1)
	{
		std::cin >> input;

		// Check if any decimals or non numbers entered
		int i = 0;	// used as counter
		while(!charPresent && i < input.length())
		{
			// If any characters in string are not integers set boolean to true
			if(!isdigit(input[i]))
			{
				charPresent = true;
			}			 
			i++;    // increment counter
		} 

		if(!charPresent)					
		{
			inputAsLong = strtol(input.c_str(), &ptr, 10); 	 // Used this website to troubleshoot function ://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm    
			if(inputAsLong > 0 && inputAsLong <= maxValue)	 // If value is between 1 and passed in value
			{
				return inputAsLong;			 // returns value if int in range
			}
			else
			{
				std::cout << "\nPlease enter an integer between 0 and " << maxValue << ":" <<  std::endl;
			}
		}
		else
		{
			std::cout << "Please enter a valid integer:\n";
		}
		std::cin.clear();	//clears error flag
	
		// Resets boolean so we may loop again and see if user enters valid integer
		charPresent = false;   		
		std::cin.clear();	//clears error flag
	}
}
