//Table to store gameboard.
#ifndef game_field_hpp
#define game_field_hpp

const int window_width = 50;
const int title_height = 3;
const int field_height = 50;
const int log_height = 7;
enum Status {EMPTY, GROWN_MALE, GROWN_FEMALE, BABY_MALE, BABY_FEMALE, VAMPIRE, ERROR };

class Green_fields
{
	public:
	Green_fields();
	void set_field(int y, int x, Status bunny_state);
	Status field_state(int y, int x);
	char print_field(int y, int x);
	private:
	Status fields[window_width][field_height];
};

#endif
