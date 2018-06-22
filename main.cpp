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

using namespace std;

vector <string> Log_text;
Green_fields bunny_fields;
/************************************MAIN******************************/
int main()
{
	srand(time(NULL));
	
	int sposy = 1;
	int sposx = 1;
	initscr();
	bunny_herd test_herd;
	for(int i=0; i<5; i++)
	{
		test_herd.add_bunny();
	}
	Green_fields Bunny_fields;

	noecho();
	cbreak();
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE); 	//Title
	init_pair(2, COLOR_WHITE, COLOR_GREEN); //Bunny fields
	init_pair(3, COLOR_WHITE, COLOR_BLUE);	//Log window
	WINDOW *Title = newwin(title_height, window_width, sposy, sposx);
	WINDOW *Bunny_field = newwin(field_height, window_width, sposy+title_height, sposx);
	WINDOW *Log = newwin(log_height, window_width, sposy+title_height+field_height, sposx);
	scrollok(Log, TRUE);
	char quit = ' ';
	int turn_counter = 1;
	wbkgd(Title, COLOR_PAIR(1));
	wbkgd(Bunny_field, COLOR_PAIR(2));
	wbkgd(Log, COLOR_PAIR(3));
	wprintw(Title, "Radioactive Vampire Bunny Attack!");
	refresh();
	wrefresh(Title);
	while( quit != 'q' && quit != 'Q')
	{
		for(int i=0; i<field_height; i++)
		{
			for(int j=0; j<window_width; j++)
			{
				mvwprintw(Bunny_field, i, j, "%c", Bunny_fields.print_field(i, j));
			}
		}
		wrefresh(Bunny_field); 
		test_herd.live_bunnies();
		for( int i=0; i<Log_text.size(); i++)
		{
			wprintw(Log, "%s", Log_text[i].c_str());
			napms(100);
			wrefresh(Log);
		}


		quit = getch();
		//napms(200);
		Log_text.clear();
	}

	/*

	refresh();

	{

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
	*/
	//getch();
	endwin();
	return 0;
}

/***********************************************************************************/
