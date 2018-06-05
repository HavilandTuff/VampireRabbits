//bunny_herd class .hpp
#ifndef bunny_herd_hpp
#define bunny_herd_hpp
#include <iostream>
#include <string>
#include <vector>
#include "ncurses.h"
#include "bunny.hpp"
using namespace std;
extern vector <string> Log_text;
class bunny_herd
{
public:
	bunny_herd();
	int bunny_count();
	int mutants_count();
	void list_bunnies();
	void live_bunnies();
	void add_bunny(); 
	void get_MAX_BUNNY_COUNT();
private:
	enum Messages 
	{
		BORN,
		DIE,
		HUNT_BEGIN,
		HUNT_SUCESS,
		HUNT_FAILUR,
		BUNNY_STATUS,
		GROW,
		NO_GRN_BUNNY,
		NO_F_BUNNY,
		NO_M_BUNNY,
		CULL,
		BREED,
		LIST,
		No_OF_BUNNIES,
	};
	bunny* bunnies_list;
	void add_age();
	void kill_bunny(bunny *toKill );
	void breed_bunnies();
	void cull_bunnies();
	void mutate_bunnies();
	void message(Messages bunny_event, bunny* current);
	
};
#endif
