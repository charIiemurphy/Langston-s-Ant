/************************************************
 * Name: Charles Kusk
 * Date: April 8, 2019
 * Description: Defines interface of Ant class
************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		int xCord;
		int yCord;
		char orientation;
		int numRows;
		int numColumns;

	public:
		Ant(int, int, char, int, int);
		void setxCord(int);
		int getxCord();
		void setyCord(int);
		int getyCord();
		void setOrientation(char);
		char getOrientation();
		void move(char**);

};


#endif
