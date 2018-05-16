	#pragma once
	#include "stdafx.h"
	#include <string>
	using namespace std;

	class Human
	{
	private:
		string name;
		int age;
		char sex;
	public:
		Human();
		Human(string nm, int ag, char sx);
		void setName(string nm);
		void setAge(int ag);
		void setSex(char sx);
		string getName();
		int getAge();
		char getSex();
		virtual void work(string work);
	};