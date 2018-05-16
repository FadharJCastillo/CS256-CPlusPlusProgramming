#include "stdafx.h"
#include "Child.h"
#include <iostream>

Child::Child(string name, int age, char sex, Parent &mom, Parent &dad)
{
	Human(name, age, sex);
	Mom = mom;
	Dad = dad;
}
void work(string work)
{
	std::cout << work;
}