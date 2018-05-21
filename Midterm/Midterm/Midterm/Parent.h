#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include "Human.h"
#include "Child.h"
using namespace std;

class Child;

class Parent : public Human
{
private:
	vector<Child*> children;
public:
	Parent();
	Parent(string nm, int age, char sx);
	Child* getChild(int index);
	void setChild(Child &ch);
	void setChildName(int index, string name);
	void work(string work);
};