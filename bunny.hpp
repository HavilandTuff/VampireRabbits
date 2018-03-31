//bunny.hpp

#ifndef bunny_hpp
#define bunny_hpp
#include <string>
//#include "bunny.cpp"
using namespace std;
/***************************Global variables****************************/
const int MAX_BUNNY_COUNT = 1000;
const int MAX_BUNNY_AGE = 10;
const int MAX_MUTANT_AGE = 50;

/***************************Class definition***************************/
class bunny
{
public:
	bunny();
	bool get_sex();
	string get_color();
	string get_name();
	bool is_mutant();
	int get_age();
	void grow_bunny();
	void mutate();
	bunny* next_bunny;
private:
	static int MUTATION_RATE;			//chances of mutation in %
	bool is_bunny_mutant;
	string color;
	int age;
	string name;
	bool sex;						// 0 - boy, 1 - girl
}; 


#endif
