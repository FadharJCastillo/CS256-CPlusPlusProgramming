#pragma once
#include "stdafx.h"
#include <string>
#include "Human.h"

using namespace std;
class Parent;

class Child : public Human
{
	
private:
	Parent * mom;
	Parent * dad;
	Child();
public:
	Child(string name, int age, char sex, Parent& mom, Parent& dad);
	void work(string work);
	
	friend class Parent;
};