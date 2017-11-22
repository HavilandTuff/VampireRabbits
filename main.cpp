#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
using namespace std;
struct bunny
{
	bool sex;
	int color;
	int age;
	string name;
	bool radioactve_mutant_bunny;
};
list<bunny> bunny_generator();
void bunny_mating();
void turn();


int main()
{
	list<bunny> bunny_list;
	cout << "Rabbit life simulator with a twist;)" << endl;
	return 0;
}
list<bunny> bunny_generator()
{
	
}
