//game_fields.cpp
#include "game_field.hpp"



Green_fields::Green_fields()
{
	for(int i=0; i<field_height; i++)
	{
		for(int j=0; j<window_width; j++)
		{
			fields[i][j] = EMPTY;
		}
	}
}

Status Green_fields::field_state(int y, int x)
{
	if( y>=field_height || x>=window_width)
	{
		return ERROR;
	}
	else
	{
		return fields[y][x];
	}
	
}
void Green_fields::set_field(int y, int x, Status bunny_state)
{
	if(y<field_height && x<window_width)
	{
		fields[y][x]=bunny_state;
	}
}
char Green_fields::print_field(int y, int x)
{
	
	switch( fields[y][x] )
	{
		case EMPTY:
		return '.';
		break;
		case VAMPIRE:
		return 'V';
		break;
		case BABY_MALE:
		return 'm';
		break;
		case GROWN_MALE:
		return 'M';
		break;
		case BABY_FEMALE:
		return 'f';
		break;
		case GROWN_FEMALE:
		return 'F';
		break;
	}
}
//Green_fields bunny_fields;
