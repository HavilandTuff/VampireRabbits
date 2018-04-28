#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "bunny.hpp"
#include "bunny_herd.hpp"
#include "game_field.hpp"
#include "ncurses.h"

using namespace std;
void draw_bunny_fields()
{
	Green_fields bunny_fields;
	for(int i; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(bunny_fields.field_state(i, j) == EMPTY)
			{
				mvprintw(i,j, "o");
			}
			else
			{
				mvprintw(i,j, "x");
			}
		}
		printw("\n");
	}
	refresh();
	getch();
}

/************************************MAIN******************************/
int main()
{
	srand(time(NULL));
	int delay = 10; //turn delay in tenth of second. Use values from 1 to 255.
	initscr();
	noecho();
	halfdelay(delay);
	char quit = ' ';
	int turn_counter = 0;
	
	bunny_herd test_herd;
	for(int i=0; i<5; i++)
	{
		test_herd.add_bunny();
	}
	refresh();
	while( quit != 'q' && quit != 'Q')
	{
		quit = getch();
		clear();
		if(quit == ERR || (quit != 'q'&& quit != 'Q'))
		{
		printw("Turn: %d \n",  turn_counter);
		test_herd.live_bunnies();
		turn_counter++;
		printw("\nTo finish press 'q' or any key to continue\n");
		
		if(test_herd.bunny_count() == test_herd.mutants_count())
			{
				clear();
				quit='q';
				printw("All bunnies perished. End of game! \n");
				refresh();
				getch();
			}
		
		}
		refresh();
	}
	draw_bunny_fields();
	refresh();
	getch();
	endwin();
	return 0;
}

