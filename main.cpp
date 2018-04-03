#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "bunny.hpp"
#include "bunny_herd.hpp"
using namespace std;

/************************************MAIN******************************/
int main()
{
	srand(time(NULL));
	char quit = ' ';
	int turn_counter = 0;
	bunny_herd test_herd;
	for(int i=0; i<5; i++)
	{
		test_herd.add_bunny();
	}
	while( quit != 'q' && quit != 'Q')
	{
		cout << "Turn: " << turn_counter << endl;
		test_herd.live_bunnies();
		turn_counter++;
		cout << "\nTo finish press 'q' or any key to continue" << endl;
		cin >> quit;
		cin.clear();
		cin.ignore( 1000, '\n' );
		if(test_herd.bunny_count()==test_herd.mutants_count()&& test_herd.bunny_count() == 0)
		{
			quit='q';
			cout << "All bunnies perished. End of game!" << endl;
		}
	}
	return 0;
}

