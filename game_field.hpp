//Table to store gameboard.
#ifndef game_field_hpp
#define game_field_hpp
#include "bunny.hpp"
enum Status {EMPTY, GROWN_MALE, GROWN_FEMALE, BABY_MALE, BABY_FEMALE, VAMPIRE, ERROR };
//Field class is 100x100 table containig informations about bunnies position.
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
#endif
