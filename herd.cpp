//herd class .cpp
#include "herd.cpp"
bunny* create_bunny(bunny* bunny_list)
{
	bunny* new_bunny = new bunny;
	if(bunny_list == nullptr)
	{
		bunny_list = new_bunny;
	}
	else
	{
		bunny* temp = bunny_list;
		while(temp->next_bunny != nullptr)
		{
			temp = temp->next_bunny;
		}
		temp->next_bunny = new_bunny;
		new_bunny->next_bunny = nullptr;
	}
	BUNNY_COUNT++;
	cout << new_bunny->get_name() << " was born!" << endl;
	return bunny_list;
}

void list_bunnies(bunny* bunny_list)
{
	int bunny_count = 0;
	int female_bunny_count = 0;
	bunny* current_bunny=bunny_list;
	while(current_bunny != nullptr)
	{
		cout << "Bunny " << current_bunny->get_name() 
		<< " color: " << current_bunny->get_color() 
		<< " age: " << current_bunny->get_age() 
		<< " and is mutant: " << current_bunny->is_mutant() << endl;
		bunny_count++;
		if(current_bunny->get_sex() == 1)
		female_bunny_count++;
		current_bunny = current_bunny->next_bunny;
		
	}
	cout << "Bunny count: " << bunny_count
		 << " and females is: " << female_bunny_count 
		 << " number of mutants: " << mutants_count << endl;
	
}

void add_age(bunny* &bunny_list)
{
	bunny* previous = nullptr;
	bunny* current_bunny=bunny_list;
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
		kill_bunny(bunny_list, previous, current_bunny);
	}
}

void kill_bunny(bunny* &bunny_list, bunny* &previous, bunny* &current)
{
		if ( previous == nullptr)
		{
			cout << "Bunny " << current->get_name() << " died!" << endl;
			bunny_list = current->next_bunny;
			delete current;
			current = bunny_list;
		}
		else
		{
			cout << "Bunny " << current->get_name() << " died!" << endl;
			previous->next_bunny = current->next_bunny;
			delete current;
			current = previous->next_bunny;
		}
		BUNNY_COUNT--;
}

void breed_bunnies(bunny* bunny_list)
{
	
	int grown_female_bunny_count = 0;
	int grown_bunny = 0;
	bunny* temp = bunny_list;
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
		 for( int i=0; i<grown_female_bunny_count && BUNNY_COUNT < MAX_BUNNY_COUNT; i++)
		 {
			 create_bunny(bunny_list);
		 }
	 }
	 else if(grown_female_bunny_count == 0)
	 {
		 cout << "No grown girls! Cannot breed!" << endl;
	 }
	 else if( grown_bunny == 0)
	 {
		 cout << "No adult bunnies! Cannot breed!" << endl;
	 }
	 else
	 cout << "No boys! Cannot breed!" << endl;
}		

void cull_bunnies(bunny* &bunny_list)
{
	
	bunny* previous = nullptr;
	bunny* current_bunny=bunny_list;
	{
		while(current_bunny != nullptr)
		{
			if(rand()%2)
			kill_bunny(bunny_list, previous, current_bunny);
			else
			{
				previous = current_bunny;
				current_bunny = current_bunny->next_bunny;
			}
		}
	}
}
