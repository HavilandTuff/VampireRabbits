//herd class .hpp
#ifndef herd_hpp
#define herd_hpp
#include <iostream>
#include <string>
using namespace std;
class bunny_herd
{
public:
	bunny_herd();
	int bunny_count();
	int mutants_count();
	void list_bunnies();
	void live_bunnies();
private:
	const int MAX_BUNNY_COUNT = 1000;
	const int MAX_BUNNY_AGE = 10;
	const int MAX_MUTANT_AGE = 50;
	int BUNNY_COUNT;
	int mutants_count;
	bunny* bunnies_list = nullptr;
	void add_age(bunny* &bunny_list);
	void kill_bunny(bunny* &bunny_list, bunny* &previous, bunny* &current);
	void breed_bunnies(bunny* bunny_list);
	void cull_bunnies(bunny* &bunny_list);
};
#endif
