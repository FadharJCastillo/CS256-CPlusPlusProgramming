#include "stdafx.h"
#include "Parent.h"
#include "Child.h"
#include <iostream>
Parent::Parent()
{
	Human();
}
Parent::Parent(string nm, int age, char sx)
{
	Human(nm, age, sx);
}
Child Parent::getChild(int index)
{
	if (index < children.size())
	{
		return children[index];
	}
}
void Parent::setChild(Child& ch)
{
	children.push_back(ch);
}
void Parent::setChildName(int index, string name)
{
	if (index < children.size())
	{
		children[index].setName(name);
	}
}
void Parent::work(string work)
{
	std::cout << work;
}