/***************************************************************
 * Name: Charles Kusk
 * Date: April 8, 2019
 * Description: Prints out board
***************************************************************/

#include <iostream>
#include "displayBoard.hpp"

void displayBoard(char **board, int rows, int columns)
{
	std::cout << std::endl;
	for(int x = 0; x < rows; x++)
	{
		for(int y = 0; y < columns; y++)
		{
			std::cout << board[x][y] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
