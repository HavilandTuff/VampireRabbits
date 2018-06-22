//bunny.hpp

#ifndef bunny_hpp
#define bunny_hpp
#include <string>
#include "game_field.hpp"
//using namespace std;
/***************************Global variables****************************/
const int MAX_BUNNY_COUNT = 1000;
const int MAX_BUNNY_AGE = 10;
const int MAX_MUTANT_AGE = 50;

/***************************Class definition***************************/
class bunny
{
	private:
	struct Position
	{
		int y;
		int x;
	};	
public:
	bunny();
	bool get_sex();
	std::string get_color();
	std::string get_name();
	bool is_mutant();
	int get_age();
	void grow_bunny();
	void mutate();
	void set_bunny_position( int y, int x);
	Position get_position();
	void jump(Green_fields* bunny_field);
	Status get_status();
	bunny* next_bunny;
private:
	static int MUTATION_RATE;			//chances of mutation in %
	bool is_bunny_mutant;
	std::string color;
	int age;
	std::string name;
	bool sex;	// 0 - boy, 1 - girl
	Position bunny_position;
	bool is_jump_valid(int y, int x, Green_fields* bunny_field);
	
}; 


#endif
