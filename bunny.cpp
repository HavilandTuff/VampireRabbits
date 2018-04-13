#include <string>
#include <iostream>
#include "names.hpp"
#include "bunny.hpp"


/**************************Class methods********************************/
int bunny::MUTATION_RATE=2;
bunny::bunny()
{
	age = 0;
	if(rand()%100 < MUTATION_RATE)
	{
		is_bunny_mutant = true;
		name = mutants_names[rand()%mutants_names.size()];
	}	
	else
	is_bunny_mutant = false;
	color = colors[rand()%colors.size()];
	if(is_bunny_mutant==false)
	{
	sex = rand()%2;
	color = colors[rand()%colors.size()];
	if(sex == 0)
	name = boys_names[rand()%boys_names.size()];
	else
	name = girls_names[rand()%girls_names.size()];
	}
	next_bunny = nullptr;
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
