#include "stdafx.h"
#include "Human.h"

Human::Human()
{
	name = "";
	age = 0;
	sex = ' ';
}
Human::Human(string nm, int ag, char sx)
{
	name = nm;
	age = ag;
	sex = sx;
}
void Human::setName(string nm)
{
	name = nm;
}
void Human::setAge(int ag)
{
	age = ag;
}
void Human::setSex(char sx)
{
	sex = sx;
}
string Human::getName()
{
	return name;
}
int Human::getAge()
{
	return age;
}
char Human::getSex()
{
	return sex;
}