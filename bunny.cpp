#include <string>
#include <iostream>

#include "bunny.h"
using namespace std;
string boys_names[] = { "Bob", "Tom", "Rob"};
int bunny::get_age()
{
	return age;
}
void bunny::set_age(int change_age)
{
	if(change_age <+ 0)
	cout << "Wrong age change!" << endl;
	else
	age += change_age;
}

