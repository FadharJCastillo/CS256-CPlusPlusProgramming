#include "stdafx.h"
#include "Parent.h"
#include "Child.h"
#include <iostream>
Parent::Parent()
{
	Human();
}
Parent::Parent(string nm, int age, char sx) :
	Human(nm, age, sx) {}
Child* Parent::getChild(int index)
{ 
	Child *c = NULL;
	if (index < (int)children.size())
	{
		c = children[index];
	}
	return c;
}
void Parent::setChild(Child& ch)
{
	children.push_back(&ch);
}
void Parent::setChildName(int index, string name)
{
	if (index < (int)children.size())
	{
		children[index]->setName(name);
	}
}
void Parent::work(string work)
{
	std::cout << work;
}