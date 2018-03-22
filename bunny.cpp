#include <string>
#include <iostream>

#include "bunny.hpp"
/*
#include "bunny.h"
using namespace std;
string boys_names[] = { "Bob", "Tom", "Rob"};
int bunny::get_age()
{
	return age;
}
void bunny::set_age(int change_age)
{
	if(change_age <+ 0)
	cout << "Wrong age change!" << endl;
	else
	age += change_age;
}

*/
bunny::bunny()
{
	age = 0;
	if(rand()%100 < MUTATION_RATE)
	{
		is_bunny_mutant = true;
		name = mutants_names[rand()%mutants_names.size()];
		mutants_count++;
	}	
	else
	is_bunny_mutant = false;
	sex = rand()%2;
	color = colors[rand()%colors.size()];
	if(sex == 0)
	name = boys_names[rand()%boys_names.size()];
	else
	name = girls_names[rand()%girls_names.size()];
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
void bunny::mutate()
{
	is_bunny_mutant=true;
	name = mutants_names[rand()%mutants_names.size()];
}
