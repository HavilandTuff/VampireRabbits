//bunny_herd.cpp
#include "bunny_herd.hpp"
/*
class bunny_herd
{
public:
	bunny_herd();
	int bunny_count();
	int mutants_count();
	void list_bunnies();
	void live_bunnies();
private:
	const int MAX_BUNNY_COUNT = 1000;
	const int MAX_BUNNY_AGE = 10;
	const int MAX_MUTANT_AGE = 50;
	bunny* bunnies_list;
	void add_age(bunny* &bunny_list);
	void kill_bunny(bunny* &bunny_list, bunny* &previous, bunny* &current);
	void breed_bunnies(bunny* bunny_list);
	void cull_bunnies(bunny* &bunny_list);
	void add_bunny(bunny* bunny_list) //adds single random bunny.
};
*/

bunny_herd::bunny_herd()
{
	bunnies_list=nullptr;
}
int bunny_herd::bunny_count()
{
	int count = 0;
	bunny* current_bunny=bunnies_list;
	while(current_bunny != nullptr)
	{
		current_bunny=current_bunny->next_bunny;
		count++;
	}
	return count;
}
int bunny_herd::mutants_count()
{
	int count = 0;
	bunny* current_bunny=bunnies_list;
	while(current_bunny != nullptr)
	{
		if(current_bunny->is_mutant() == true)
		count++;
		current_bunny=current_bunny->next_bunny;
		
	}
	return count;
}
void bunny_herd::list_bunnies()
{
	bunny* current_bunny=bunnies_list;
	while(current_bunny != nullptr)
	{
		cout << "Królik: " << current_bunny->get_name() << endl;
		current_bunny=current_bunny->next_bunny;
	}
}
void bunny_herd::live_bunnies()
{
}
void bunny_herd::add_bunny()
{
	bunny* new_bunny = new bunny;
	if(bunnies_list == nullptr)
	{
		bunnies_list = new_bunny;
	}
	else
	{
		bunny* temp = bunnies_list;
		while(temp->next_bunny != nullptr)
		{
			temp = temp->next_bunny;
		}
		temp->next_bunny = new_bunny;
		new_bunny->next_bunny = nullptr;
	}
	cout << new_bunny->get_name() << " was born!" << endl;
}
void bunny_herd::add_age()
{
	bunny* temp = bunnies_list;
		do
		{
			temp->grow_bunny();
			temp = temp->next_bunny;
		}while(temp->next_bunny != nullptr);
}
