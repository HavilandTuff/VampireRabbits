

#ifndef bunny_hpp
#define bunny_hpp
#include <string>
#include "bunny.cpp"
using namespace std;
enum BUNNY_COLOR{ BROWN, WHITE, BLACK, SPOTTED };
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
	static const int MUTATION_RATE = 2;			//chances of mutation in %
	bool is_bunny_mutant;
	string color;
	int age;
	string name;
	bool sex;						// 0 - boy, 1 - girl
}; 


#endif
