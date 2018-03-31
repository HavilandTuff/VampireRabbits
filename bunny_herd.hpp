//bunny_herd class .hpp
#ifndef bunny_herd_hpp
#define bunny_herd_hpp
#include <iostream>
#include "bunny.hpp"
//using namespace std;
class bunny_herd
{
public:
	bunny_herd();
	int bunny_count();
	int mutants_count();
	void list_bunnies();
	void live_bunnies();
	void add_bunny(); //adds single random bunny.
	void get_MAX_BUNNY_COUNT();
private:
	//const int MAX_BUNNY_COUNT = 1000;
	//const int MAX_BUNNY_AGE = 10;
	//const int MAX_MUTANT_AGE = 50;
	bunny* bunnies_list;
	void add_age();
	void kill_bunny(bunny* &previous, bunny* &current );
	void breed_bunnies();
	void cull_bunnies();
	void mutate_bunnies();
	
};
#endif
