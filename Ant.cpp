/***************************************************************
 * Name: Charles Kusk
 * Date: April 8, 2019
 * Description: Implements member functions of Ant class
***************************************************************/

#include <iostream>
#include "Ant.hpp"

/**************************************************************
 * Description: Constructor for Ant class
**************************************************************/
Ant::Ant(int yIn, int xIn, char orientationIn, int rows, int columns)
{
	yCord = yIn;
	xCord = xIn;
	orientation = orientationIn;
	numRows = rows;
	numColumns = columns;
}

void Ant::setxCord(int xIn)
{
	xCord = xIn;
}

int Ant::getxCord()
{
	return xCord;
}

void Ant::setyCord(int yIn)
{
	yCord = yIn;
}

int Ant::getyCord()
{
	return yCord;
}

void Ant::setOrientation(char orientationIn)
{
	orientation = orientationIn;
}

char Ant::getOrientation()
{
	return orientation;
}

/*************************************************************
 * Description: Changes color of square and moves ant
*************************************************************/
void Ant::move(char **board)
{
	// If ant lands on white space
	if(board[yCord][xCord] == ' ')
	{
		board[yCord][xCord] = '#';
		
		if(orientation == 'u')			// if ant is facing up
		{
			orientation = 'r';		// turn ant 90 degrees to right for landing on white
			if(xCord + 1 >= numColumns)     // if ant hits right wall
			{
				orientation = 'l';	// flip ant around
				xCord--;		// move ant one space to the left
			}
			else				// Ant did not hit wall
			{
				xCord++;		// Ant moves one spot to right
			}
		}
		else if(orientation == 'r')		// if ant is facing right
		{
			orientation = 'd';
			if(yCord + 1 >= numRows)	// if ant hits bottom wall
			{
				orientation = 'u';	// flip ant
				yCord--;		// Ant moves one spot up
			}
			else
			{
				yCord++;		// Ant moves down 
			}
		}
		else if(orientation == 'd')		// if ant is facing down
		{
			orientation = 'l';		// Ant turns 90 degrees right and faces left
			if(xCord == 0)			// if ant is at left wall
			{
				orientation = 'r';	// flip ant
				xCord++;		// ant moves one spot to right 
			}
			else
			{
				xCord--;		// ant moves left
			}
		}
		else					// ant is facing left
		{
			orientation = 'u';		// turn ant up
			if(yCord == 0)			// ant hits top wall
			{
				orientation = 'd';	// face ant down
				yCord++;		// ant moves down one
			}
			else	
			{
				yCord--;
			}
		}		
	}

	// If ant lands on black space
	else if(board[yCord][xCord] == '#')
	{
		board[yCord][xCord] = ' ';		// changes space to white (will be space later)

		
		if(orientation == 'u')			// if ant is facing up
		{
			orientation = 'l';		// turn ant 90 degrees to left for landing on white
			if(xCord == 0)                  // if ant hits left wall
			{
				orientation = 'r';	// flip ant around
				xCord++;		// move ant one space to the right
			}
			else				// Ant did not hit wall
			{
				xCord--;		// Ant moves one spot to left
			}
		}
		else if(orientation == 'r')		// if ant is facing right
		{
			orientation = 'u';
			if(yCord == 0)			// if ant hits top wall
			{
				orientation = 'd';	// flip ant
				yCord++;		// Ant moves down spot up
			}
			else
			{
				yCord--;		// Ant moves up 
			}
		}
		else if(orientation == 'd')		// if ant is facing down
		{
			orientation = 'r';		// Ant turns 90 degrees left and faces right
			if(xCord + 1 >=  numColumns)	// if ant is at right wall
			{
				orientation = 'l';	// flip ant
				xCord--;		// ant moves one spot to left 
			}
			else
			{
				xCord++;		// ant moves one spot to right
			}
		}
		else					// orientation = 'l'	
		{
			orientation = 'd';
			if(yCord + 1 >= numRows)	// if ant is at bottom wall
			{
				orientation = 'u';	// turn ant up
				yCord--;		// move ant up one space
			}
			else
			{
				yCord++;		// move ant down one space
			}
		}		
	}
	else
	{
		std::cout << "Error with square colors on board!!!\n\n\n";
	}
}

