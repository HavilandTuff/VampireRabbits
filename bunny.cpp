#include <string>
#include "names.hpp"
#include "bunny.hpp"
#include "game_field.hpp"

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
	{
		is_bunny_mutant = false;
		sex = rand()%2;
		if(sex == 0)
			name = boys_names[rand()%boys_names.size()];
		else
			name = girls_names[rand()%girls_names.size()];
	}
	color = colors[rand()%colors.size()];
	bunny_position.y=0;
	bunny_position.x=0;
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
void bunny::set_bunny_position(int y, int x)
{
	bunny_position.y=y;
	bunny_position.x=x;
}
bool bunny::is_jump_valid(int y, int x, Green_fields* bunny_field)
{
	if( y>=field_height || x>=window_width || y<0 || x<0)
	{
		return false;
	}
	else if(bunny_field->field_state(y, x) != EMPTY || 
	bunny_field->field_state(y, x) == ERROR)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void bunny::jump(Green_fields* bunny_field)
{
	
	int y, x;
	do
	{
		y= this->bunny_position.y;
		x= this->bunny_position.x;
		y=rand()%2 ? y++ : y--;
		x=rand()%2 ? x++ : x--;
	}while(!is_jump_valid(y, x, bunny_field));
	this->bunny_position.y=y;
	this->bunny_position.x=x;
	Status bunny_status = this->get_status();
	bunny_field->set_field( y, x, bunny_status ); 
}

Status bunny::get_status()
{
	if(this->is_bunny_mutant == true)
		return VAMPIRE;
	else if(this->sex == true && this->age > 2)
		return GROWN_MALE;
	else if(this->sex == true && this->age <= 2)
		return BABY_MALE;
	else if(this->sex == false && this->age >2)
		return GROWN_FEMALE;
	else
		return BABY_FEMALE;
}
