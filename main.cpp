#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "names.hpp"
using namespace std;

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
	bunny* next_bunny;
private:
	bool is_bunny_mutant;
	string color;
	int age;
	string name;
	bool sex;						// 0 - boy, 1 - girl
};

bunny*create_bunny(bunny* bunny_list);
void list_bunnies(bunny* bunny_list);
void add_age(bunny* bunny_list);
void kill_bunny(bunny* bunny_list);

/***********************************Global variables*******************/
static int MAX_BUNNY_COUNT = 1000;
int bunny_count = 0;
int female_bunny_count = 0;
static int MUTATION_RATE = 2;		//chances of mutation in %

int main()
{
	srand(time(NULL));
	bunny* bunnies_list = NULL;
	char quit = ' ';
	for(int i = 0; i<5; i++)
	{
	bunnies_list = create_bunny(bunnies_list);
	}
	list_bunnies(bunnies_list);
	while( quit != 'q' && quit != 'Q')
	{
		add_age(bunnies_list);
		cout << "Bunnies aged: " << endl;
		list_bunnies(bunnies_list);
		cout << "Bunny count: " << bunny_count << endl;
		kill_bunny(bunnies_list);
		cout << "\nTo finish press 'q' or any key to continue" << endl;
		cin >> quit;
		cin.clear();
		cin.ignore( 1000, '\n' );
	}
	return 0;
}
/******************************************functions***********************************************/
bunny* create_bunny(bunny* bunny_list)
{
	bunny* new_bunny = new bunny;
	if(bunny_list == NULL)
	{
		bunny_list = new_bunny;
	}
	else
	{
		bunny* temp = bunny_list;
		while(temp->next_bunny != NULL)
		{
			temp = temp->next_bunny;
		}
		temp->next_bunny = new_bunny;
		new_bunny->next_bunny = NULL;
	}
	bunny_count++;
	if(new_bunny->get_sex() == 1)
	female_bunny_count++;
	return bunny_list;
}

void list_bunnies(bunny* bunny_list)
{
	bunny* current_bunny=bunny_list;
	while(current_bunny != NULL)
	{
		cout << "Bunny " << current_bunny->get_name() 
		<< " sex = " << current_bunny->get_sex()
		<< " color: " << current_bunny->get_color() 
		<< " age: " << current_bunny->get_age() 
		<< " and is mutant: " << current_bunny->is_mutant() 
		<< " girls number: " << female_bunny_count << endl;
		current_bunny = current_bunny->next_bunny;
	}
}

void add_age(bunny* bunny_list)
{
	bunny* current_bunny=bunny_list;
	while(current_bunny != NULL)
	{
		current_bunny->grow_bunny();
		current_bunny = current_bunny->next_bunny;
	}
}
void kill_bunny(bunny* bunny_list)
{
	bunny* previous = NULL;
	bunny* current = bunny_list;
	int count = 0;
	while(current != NULL)
	{
		if(count == 3)
		{
			previous->next_bunny = current->next_bunny;
			delete current;
			current = previous;
			bunny_count--;
		}
		previous = current;
		current = current->next_bunny;
		count++;
	}
}
	
		
/****************************class methods*********************************************************/
bunny::bunny()
{
	age = 0;
	if(rand()%100 < MUTATION_RATE)
	is_bunny_mutant = true;
	else
	is_bunny_mutant = false;
	sex = rand()%2;
	color = colors[rand()%colors.size()];
	name = boys_names[rand()%boys_names.size()];
}
int bunny::get_age()
{
	return age;
}
void bunny::grow_bunny()
{
	age++;
}
bool bunny::get_sex()
{
	return sex;
}
string bunny::get_color()
{
	return color;
}
string bunny::get_name()
{
	return name;
}
bool bunny::is_mutant()
{
	return is_bunny_mutant;
}
