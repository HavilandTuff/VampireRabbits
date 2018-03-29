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
		cout << "Bunny: " << current_bunny->get_name() 
		<< ", age: " << current_bunny->get_age() << endl;
		current_bunny=current_bunny->next_bunny;
	}
}

void bunny_herd::live_bunnies()
{
	cout << "Bunnies grow. " << endl;
	add_age();
	cout << "Bunnies breed. " << endl;
	breed_bunnies();
	if(bunny_count() >= MAX_BUNNY_COUNT)
	{
		cout << "\n**** May The Hunger Games begin! ****\n" << endl;
		cull_bunnies();
	}
	cout << "List of Bunnies" << endl;
	list_bunnies();
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

void bunny_herd::kill_bunny(bunny* previous, bunny* current )
{
	
	
	if ( previous == nullptr)
		{
			cout << "Bunny " << current->get_name() << " died!" << endl;
			bunnies_list = current->next_bunny;
			delete current;
			current = bunnies_list;
		}
	else
		{
			cout << "Bunny " << current->get_name() << " died!" << endl;
			previous->next_bunny = current->next_bunny;
			delete current;
			current = previous->next_bunny;
		}
}

void bunny_herd::add_age()
{
	bunny* previous = nullptr;
	bunny* current_bunny=bunnies_list;
	while(current_bunny != nullptr)
	{
		if (current_bunny->get_age() < MAX_BUNNY_AGE || 
		(current_bunny->is_mutant() == true && current_bunny->get_age() < MAX_MUTANT_AGE))
		{
			current_bunny->grow_bunny();
			previous = current_bunny;
			current_bunny = current_bunny->next_bunny;
		}
		else
		kill_bunny( previous, current_bunny);
	}
}
void bunny_herd::cull_bunnies()
{
	
	bunny* previous = nullptr;
	bunny* current_bunny=bunnies_list;
	{
		while(current_bunny != nullptr)
		{
			if(rand()%2)
			kill_bunny( previous, current_bunny);
			else
			{
				previous = current_bunny;
				current_bunny = current_bunny->next_bunny;
			}
		}
	}
}

void bunny_herd::breed_bunnies()
{
	int grown_female_bunny_count = 0;
	int grown_bunny = 0;
	bunny* temp = bunnies_list;
	while (temp != nullptr)
	{
		if(temp->get_age() >=2)
		grown_bunny++;
		if(temp->get_sex() == 1 && temp->is_mutant() == false && temp->get_age() >=2)
		grown_female_bunny_count++;
		temp = temp->next_bunny;
	}
	 if(grown_bunny > 0 && grown_female_bunny_count !=0 && grown_bunny != grown_female_bunny_count)
	 {
		 for( int i=0; i<grown_female_bunny_count && bunny_count() < MAX_BUNNY_COUNT; i++)
		 {
			 add_bunny();
		 }
	 }
	else if( grown_bunny == 0)
	 {
		 cout << "No adult bunnies! Cannot breed!" << endl;
	 }
	  else if(grown_female_bunny_count == 0)
	 {
		 cout << "No grown girls! Cannot breed!" << endl;
	 }
	 else
	 cout << "No boys! Cannot breed!" << endl;
}
