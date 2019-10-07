/*********************************************************
 * Name: Charles Kusk
 * Date: April 8, 2019
 * Description: Defines menu function and performs input validation
**********************************************************/

#include <iostream>
#include <cctype>	// isdigit()
#include <string>	// std::string, std::stoi
#include <stdlib.h>	// strtol()
#include "antMenu.hpp"

int antMenu(std::string prompt)
{		
	bool charPresent = false;
	std::string input;
	long inputAsLong;		// Needed to use long to use strtol
	char *ptr;			// Needed this pointer for strtol, not sure why
	
	// Repeats loop until a valid integer is entered
	while(1)
	{
		
		std::cout << prompt;
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
			
		inputAsLong = strtol(input.c_str(), &ptr, 10); 	 // Used this website to troubleshoot function ://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm  
		// If no non integers are present
		if(!charPresent)
		{	
			if(inputAsLong == 1)				 //User selects 1
			{
				std::cout << "\n\n";
				return 1;
			}
			else if(inputAsLong == 2)			 //User selects 2
			{	
				return 0;
			}
			else
			{
				std::cout << "\nPlease enter a valid number (1 or 2)\n\n\n";
			}
			
		}
		// Resets boolean so we may loop again and see if user enters valid integer
		charPresent = false;   		
		std::cin.clear();	//clears error flag
	}
}
