#include <string>
enum BUNNY_COLOR{ BROWN, WHITE, BLACK, SPOTTED };
class bunny
{
	public:
	//bunny();
	//bool get_sex();
	//BUNNY_COLOR get_color();
	//std::string get_name();
	//bool is_mutant();
	int get_age();
	void set_age(int change_age);
	bunny* next_bunny;
	private:
	//bool sex;
	//BUNNY_COLOR color;
	int age;
	//std::string name;
	//bool is_bunny_mutant;
	//std:: string set_name( bool sex );
};
