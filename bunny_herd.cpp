//bunny_herd.cpp
#include "bunny_herd.hpp"
#include "tools.hpp"
using namespace std;
/*
class bunny_herd
{
public:
	bunny_herd();
	int bunny_count();
	int mutants_count();
	void list_bunnies();
	void live_bunnies();
	void add_bunny(); 
	void get_MAX_BUNNY_COUNT();
private:
	enum Messages 
	{
		BORN,
		DIE,
		HUNT_BEGIN,
		HUNT_SUCESS,
		HUNT_FAILUR,
		BUNNY_STATUS,
		GROW,
		NO_GRN_BUNNY,
		NO_F_BUNNY,
		NO_M_BUNNY,
		CULL,
		BREED,
		LIST,
		No_OF_BUNNIES,
	};
	bunny* bunnies_list;
	void add_age();
	void kill_bunny(bunny* &previous, bunny* &current );
	void breed_bunnies();
	void cull_bunnies();
	void mutate_bunnies();
	void message(Messages event, bunny* current);
	
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
		message(BUNNY_STATUS, current_bunny);
		current_bunny=current_bunny->next_bunny;
	}
}

void bunny_herd::live_bunnies()
{
	message(GROW, nullptr);
	add_age();
	message(BREED, nullptr);
	breed_bunnies();
	if(bunny_count() >= MAX_BUNNY_COUNT)
	{
		message(CULL, nullptr);
		cull_bunnies();
	}
	if(mutants_count() != 0)
	message(HUNT_BEGIN, nullptr);
	mutate_bunnies();
	message(LIST, nullptr);
	list_bunnies();
	message(No_OF_BUNNIES, nullptr);
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
	message(BORN, new_bunny);
}

void bunny_herd::kill_bunny(bunny* toKill)
{
	bunny* curr = bunnies_list;
	if(toKill == curr)
	{
		bunnies_list = curr->next_bunny;
		message(DIE, toKill);
		delete toKill;
	}
	while(curr != nullptr)
	{
		if( curr->next_bunny == toKill)
		{
			curr->next_bunny = toKill->next_bunny;
			message(DIE, toKill);
			delete toKill;
		}
		else
		curr = curr->next_bunny;
	}
}

void bunny_herd::add_age()
{
	bunny* current_bunny=bunnies_list;
	while(current_bunny != nullptr)
	{
		if (current_bunny->get_age() < MAX_BUNNY_AGE || 
		(current_bunny->is_mutant() == true && current_bunny->get_age() < MAX_MUTANT_AGE))
		{
			current_bunny->grow_bunny();
			current_bunny = current_bunny->next_bunny;
		}
		else
		{
			kill_bunny(current_bunny);
			current_bunny = bunnies_list;
		}
	}
}
void bunny_herd::cull_bunnies()
{
	int no_to_cull = MAX_BUNNY_COUNT/2;
	int bunny_to_kill = 0;
	bunny* temp = nullptr;
	for(int i=0; i<no_to_cull; i++)
	{
		bunny_to_kill = rand()%bunny_count();
		temp = bunnies_list;
		for( int j = 0; j<bunny_to_kill; j++)
		{
			temp = temp->next_bunny;
		}
		kill_bunny(temp);
	}
}

void bunny_herd::breed_bunnies()
{
	int grown_female_bunny_count = 0;
	int grown_bunny = 0;
	bunny* temp = bunnies_list;
	while (temp != nullptr)
	{
		if(temp->get_age() >=2 && temp->is_mutant() == false)
		grown_bunny++;
		if(temp->get_sex() == 1 && temp->is_mutant() == false && temp->get_age() >=2)
		grown_female_bunny_count++;
		temp = temp->next_bunny;
	}
	
	 if(grown_female_bunny_count !=0 && grown_bunny != grown_female_bunny_count)
	 {
		 for( int i=0; i<grown_female_bunny_count && bunny_count() < MAX_BUNNY_COUNT; i++)
		 {
			 add_bunny();
		 }
	 }
	else if( grown_bunny == 0)
	 {
		message(NO_GRN_BUNNY, nullptr);
	 }
	  else if(grown_female_bunny_count == 0)
	 {
		 message(NO_F_BUNNY, nullptr);
	 }
	 else
		message(NO_M_BUNNY, nullptr);
}
void bunny_herd::mutate_bunnies()
{
	if(bunny_count() != mutants_count())
	{
	bunny* temp=bunnies_list;
	int bunnies=bunny_count();
	int mutations=mutants_count();
	bool mutated=false;
	int be_mutant=0;
	
	while(mutations != 0)
	{
		while(mutated==false)
		{
			be_mutant=rand()%bunnies;
			for(int i=0; i < be_mutant; i++)
			{
				temp=temp->next_bunny;
			}
			if(temp->is_mutant() == false && rand()%2==true) //Bunny has 50/50 chance to survive vampire atack.
			{
				message(HUNT_SUCESS, temp);
				mutated=true;
			}
			else if(temp->is_mutant() == false)
			{
				message(HUNT_FAILUR, temp);
				mutated=true;
			}
			temp=bunnies_list;
		}
		if(bunny_count()==mutants_count())
		break;
		mutations--;
		mutated=false;
		
	}
	}
}	
void bunny_herd::message(Messages event, bunny* current)
{
	switch(event)
	{
		case BORN:
		{
			cout << current->get_name() << " was born!" << endl;
			break;
		}
		case DIE:
		{
			cout << "Bunny " << current->get_name() << " died!" << endl;
			break;
		}
		case HUNT_BEGIN:
		{
			cout << "Radioactive vampire mutant bunnies go hunting!" << endl;
			break;
		}
		case HUNT_FAILUR:
		{
			cout << "Bunny " << current->get_name() << " survived vampire attack." << endl;
			break;
		}
		case HUNT_SUCESS:
		{
			cout << "Bunny " << current->get_name() << " has been bitten and now is vampire ";
			current->mutate();
			cout << current->get_name() << endl;
			break;
		}
		case NO_GRN_BUNNY:
		{
			 cout << "No adult bunnies! Cannot breed!" << endl;
			 break;
		}
		case NO_F_BUNNY:
		{
			cout << "No grown girls! Cannot breed!" << endl;
			break;
		}
		case NO_M_BUNNY:
		{
			cout << "No boys! Cannot breed!" << endl;
			break;
		}
		case BUNNY_STATUS:
		{
			cout << "Bunny: " << current->get_name() 
			<< ", age: " << current->get_age() 
			<< " sex is: " << current->get_sex();
			if(current->is_mutant() == true)
			cout << ", is vampire mutant!" << endl;
			else
			cout << endl;
			break;
		}
		case CULL:
		{
			cout << "\n**** May The Hunger Games begin! ****\n" << endl;
			break;
		}
		case GROW:
		{
			cout << "Bunnies grow. " << endl;
			break;
		}
		case BREED:
		{
			cout << "Bunnies breed. " << endl;
			break;
		}
		case LIST:
		{
			cout << "List of Bunnies" << endl;
			break;
		}
		case No_OF_BUNNIES:
		{
			cout << "Number of bunnies: " << bunny_count() << endl;
			break;
		}
		default:
		{
			cout << "Unknown operation!\n";
		}
	}
}
