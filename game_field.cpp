//game_fields.cpp
#include "game_field.hpp"
#include "ncurses.h"

/*
class Green_fields
{
	public:
	Green_fields();
	Status field_state(int y, int x);
	void draw_field();
	private:
	bool is_empty(int y, int x);
	void put_bunny(int y, int x, bunny &to_put);
	void remove_bunny(int y, int x);
	struct Field
	{
		bool is_empty;
		bunny* bunny_on_field;
	};
	Field fields[100][100];
};
*/

Green_fields::Green_fields()
{
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			fields[i][j].is_empty = true;
			fields[i][j].bunny_on_field = nullptr;
		}
	}
}
Status Green_fields::field_state(int y, int x)
{
	if( y>=100 || x>=100)
	{
		return ERROR;
	}
	else if( is_empty(y,x))
	{
		return EMPTY;
	}
	else if(fields[y][x].bunny_on_field->is_mutant() == true)
	{
		return VAMPIRE;
	}
	else if(fields[y][x].bunny_on_field->get_sex() == 0 && 
	fields[y][x].bunny_on_field->get_age() < 2)
	{
		return BABY_MALE;
	}
	else if(fields[y][x].bunny_on_field->get_sex() == 0 && 
	fields[y][x].bunny_on_field->get_age() >= 2)
	{
		return GROWN_MALE;
	}
	else if(fields[y][x].bunny_on_field->get_sex() == 1 && 
	fields[y][x].bunny_on_field->get_age() < 2)
	{
		return BABY_FEMALE;
	}
	else 
	{
		return GROWN_FEMALE;
	}
	
}
void Green_fields::draw_field()
{
}
bool Green_fields::is_empty(int y, int x)
{
	if(y < 100 && x < 100)
	{
	return fields[y][x].is_empty == true ? true:false;
	}
}
