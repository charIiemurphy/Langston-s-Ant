/************************************************************************
 * Name: Charles Kusk
 * Date: April 8, 2019
 * Description: Ant is placed on white board, if on white space turns 90 
 *              degrees right and change space to black, if on black turns
 *              90 degrees left and turns it white.  User may enter starting
 *              location and number of rows and columns and ant orientation
*************************************************************************/

#include <iostream>
#include <stdlib.h>		// srand, rand
#include "antMenu.hpp"
#include "displayBoard.hpp"
#include "Ant.hpp"
#include "validMax.hpp"

int main()
{
	int userInput, randInput, rows, columns, steps, ant_row, ant_column;
	
while(1)	
{	
	std::string prompt1 = "Would you like to start Langston's Ant simulation?\nYes = 1, No = 2 : ";
	std::string prompt2 = "\nThis is for extra credit! Would you like the ant to start at a random location?\nYes = 1, No = 2: " ;
	int stepIncrementor = 0;			// needs to be within while statement
	userInput = antMenu(prompt1);			// use menu function to ask if user wants to start simulation
		
	if(userInput == 1)
	{			
		std::cout << "How many rows in the board: ";
		rows = validMax(100);			// user may enter up to 100 rows
		std::cout << "\nHow many columns in the board: ";
		columns = validMax(100);		// user may enter up to 100 columns
		std::cout << "\nHow many steps would you like the ant to take: ";
		steps = validMax(30000);		

		randInput = antMenu(prompt2);		// ask user if theyd like random starting location for ant
		if(randInput == 1)			// randomnly assign row and column if user wants
		{
			ant_row = rand() % rows;
			ant_column = rand() % columns;
			std::cout << "\nThe ants row will be: " << ant_row;
			std::cout << "\nAnd the ants column will be: " << ant_column;
		}
		else					// lets user select row and colun
		{	
			std::cout << "\nWhich row would you like the ant to start in (count from zero): ";
			std::cin >> ant_row;
			std::cout << "\nWhich column would you like the ant to start in (count from zero): ";
			std::cin >> ant_column;
		}
		
	}
	else
	{
		std::cout << "Thank you for using my Langston's ant simulator\n\n";
		return 0;
	}

	// Initialized the ant class
	Ant langAnt(ant_row, ant_column, 'u', rows, columns);

	// Creates board and boardClone array
	char **board = new char*[rows];
	char **boardClone = new char*[rows];
	for(int i = 0; i < rows; ++i)
	{
		board[i] = new char[columns];
		boardClone[i] = new char[columns];
	}
	

	// Initializes board to be all white spaces	
	for(int y = 0; y < rows; y++)
	{
		for(int x = 0; x < columns; x++)
		{
			board[y][x] = ' ';
			boardClone[y][x] = ' ';
		}
	}
	
	// Print board
	displayBoard(boardClone, rows, columns);

	// Moves ant and prints board for every step performed
	while(stepIncrementor < steps)
	{
		// Moves Ant
		langAnt.move(board);

		// Copies board into cloneboard
		for(int y = 0; y < rows; y++)
		{
			for(int x = 0; x < columns; x++)
			{
				boardClone[y][x] = board[y][x];
			}
		}
		
		// Assigns spot ant is in as '*'
		boardClone[langAnt.getyCord()][langAnt.getxCord()] = '*';

		std::cout << "Step: " << stepIncrementor + 1 << std::endl;

		// Print Board again to show color change
		displayBoard(boardClone, rows, columns);

		stepIncrementor++;
	}

	// Clean up of array memory
	for(int i = 0; i < rows; ++i)
	{
		delete [] board[i];
		delete [] boardClone[i];
	}
	delete [] board;
	delete [] boardClone;

}
	return 0;
}
