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
	const int MUTATION_RATE = 2;		//chances of mutation in %
	bool is_bunny_mutant;
	string color;
	int age;
	string name;
	bool sex;						// 0 - boy, 1 - girl
};

bunny*create_bunny(bunny* bunny_list);
void list_bunnies(bunny* bunny_list);
void add_age(bunny* &bunny_list);
void kill_bunny(bunny* &bunny_list, bunny* &previous, bunny* &current);
void breed_bunnies(bunny* bunny_list);

/***********************************Global variables*******************/
const int MAX_BUNNY_COUNT = 1000;
int bunny_count = 0;
int female_bunny_count = 0;
int mutants_count = 0;

/************************************MAIN******************************/
int main()
{
	srand(time(nullptr));
	bunny* bunnies_list = nullptr;
	char quit = ' ';
	for(int i = 0; i<5; i++)
	{
	bunnies_list = create_bunny(bunnies_list);
	}
	list_bunnies(bunnies_list);
	while( quit != 'q' && quit != 'Q' )
	{
		add_age(bunnies_list);
		breed_bunnies(bunnies_list);
		list_bunnies(bunnies_list);
		cout << "\nTo finish press 'q' or any key to continue" << endl;
		cin >> quit;
		cin.clear();
		cin.ignore( 1000, '\n' );
	}
	return 0;
}
/******************************************functions*******************/
bunny* create_bunny(bunny* bunny_list)
{
	bunny* new_bunny = new bunny;
	if(bunny_list == nullptr)
	{
		bunny_list = new_bunny;
	}
	else
	{
		bunny* temp = bunny_list;
		while(temp->next_bunny != nullptr)
		{
			temp = temp->next_bunny;
		}
		temp->next_bunny = new_bunny;
		new_bunny->next_bunny = nullptr;
	}
	bunny_count++;
	if(new_bunny->get_sex() == 1)
	female_bunny_count++;
	return bunny_list;
}

void list_bunnies(bunny* bunny_list)
{
	bunny* current_bunny=bunny_list;
	while(current_bunny != nullptr)
	{
		cout << "Bunny " << current_bunny->get_name() 
		<< " sex = " << current_bunny->get_sex()
		<< " color: " << current_bunny->get_color() 
		<< " age: " << current_bunny->get_age() 
		<< " and is mutant: " << current_bunny->is_mutant() << endl;
		current_bunny = current_bunny->next_bunny;
	}
	cout << "Bunny count: " << bunny_count
		 << " and females is: " << female_bunny_count 
		 << " number of mutants: " << mutants_count << endl;
}

void add_age(bunny* &bunny_list)
{
	bunny* previous = nullptr;
	bunny* current_bunny=bunny_list;
	while(current_bunny != nullptr)
	{
		if (current_bunny->get_age() < 10)
		{
			current_bunny->grow_bunny();
			previous = current_bunny;
			current_bunny = current_bunny->next_bunny;
		}
		else
		kill_bunny(bunny_list, previous, current_bunny);
	}
}

void kill_bunny(bunny* &bunny_list, bunny* &previous, bunny* &current)
{
		if ( previous == nullptr)
		{
			bunny_list = current->next_bunny;
			delete current;
			current = bunny_list;
			bunny_count--;
		}
		else
		{
			previous->next_bunny = current->next_bunny;
			delete current;
			current = previous->next_bunny;
			bunny_count--;
		}
}

void breed_bunnies(bunny* bunny_list)
{
	int grown_bunny = 0;
	bunny* temp = bunny_list;
	while (temp != nullptr)
	{
		if(temp->get_age() >=2 && temp->get_sex() == true)
		grown_bunny++;
		temp = temp->next_bunny;
	}
	 if(female_bunny_count !=0 && bunny_count != female_bunny_count && grown_bunny > 0)
	 {
		 for( int i=0; i<grown_bunny; i++)
		 {
			 create_bunny(bunny_list);
		 }
	 }
	 else if(female_bunny_count == 0)
	 {
		 cout << "No girls! Cannot breed!" << endl;
	 }
	 else if( grown_bunny == 0)
	 {
		 cout << "No adoult bunnies! Cannot breed!" << endl;
	 }
	 else
	 cout << "No boys! Cannot breed!" << endl;
}		
/****************************class methods*********************************************************/
bunny::bunny()
{
	age = 0;
	if(rand()%100 < MUTATION_RATE)
	{
		is_bunny_mutant = true;
		mutants_count++;
	}	
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
