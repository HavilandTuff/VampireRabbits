//bunny_herd.cpp
#include "bunny_herd.hpp"
#include "game_field.hpp"
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
			printw("%s was born!\n", current->get_name().c_str());
			break;
		}
		case DIE:
		{
			printw("Bunny %s died!\n", current->get_name().c_str());
			break;
		}
		case HUNT_BEGIN:
		{
			printw("Radioactive vampire mutant bunnies go hunting!\n");
			break;
		}
		case HUNT_FAILUR:
		{
			printw("Bunny %s survived vampire attack.\n", current->get_name().c_str());
			break;
		}
		case HUNT_SUCESS:
		{
			printw("Bunny %s has been bitten and now is vampire ", current->get_name().c_str());
			current->mutate();
			printw(" %s \n", current->get_name().c_str());
			break;
		}
		case NO_GRN_BUNNY:
		{
			 printw("No adult bunnies! Cannot breed!\n");
			 break;
		}
		case NO_F_BUNNY:
		{
			printw( "No grown girls! Cannot breed!\n");
			break;
		}
		case NO_M_BUNNY:
		{
			printw("No boys! Cannot breed!\n");
			break;
		}
		case BUNNY_STATUS:
		{
			printw("Bunny: %s, age %d, sex is %d", 
			current->get_name().c_str(), 
			current->get_age(), 
			current->get_sex()); 
			
			if(current->is_mutant() == true)
			printw(", is vampire mutant!\n");
			else
			printw( "\n");
			break;
		}
		case CULL:
		{
			printw("\n**** May The Hunger Games begin! ****\n");
			break;
		}
		case GROW:
		{
			printw("Bunnies grow. \n");
			break;
		}
		case BREED:
		{
			printw("Bunnies breed. \n");
			break;
		}
		case LIST:
		{
			printw("List of Bunnies\n");
			break;
		}
		case No_OF_BUNNIES:
		{
			printw("Number of bunnies: %d", bunny_count());
			break;
		}
		default:
		{
			printw("Unknown operation!\n");
		}
	}
}

