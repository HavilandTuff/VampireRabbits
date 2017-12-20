#include <iostream>
#include <ncurses.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;
enum BUNNY_COLOR{ BROWN, WHITE, BLACK, SPOTTED };
class bunny
{
	public:
	bunny();
	bool get_sex();
	//BUNNY_COLOR get_color();
	//std::string get_name();
	//bool is_mutant();
	int get_age();
	void grow_bunny();
	bunny* next_bunny;
	private:
	bool sex;
	//BUNNY_COLOR color;
	int age;
	//std::string name;
	//bool is_bunny_mutant;
	//std:: string set_name( bool sex );
};

bunny*create_bunny(bunny* bunny_list);
void list_bunnies(bunny* bunny_list);
void add_age(bunny* bunny_list);
static int MAX_BUNNY_COUNT = 1000;
int bunny_count = 0;
int female_bunny_count = 0;

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
	return bunny_list;
}

void list_bunnies(bunny* bunny_list)
{
	bunny* current_bunny=bunny_list;
	while(current_bunny != NULL)
	{
		cout << "Bunny " << current_bunny->get_age() << " sex = " << current_bunny->get_sex() << endl;
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
/****************************class methods*********************************************************/
bunny::bunny()
{
	age = 0;
	sex = rand()%2;
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
