// BigNumbersLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigNumbers.h"
#include <iostream>

using namespace std;

int main()
{
	BigNumbers a("90");
	BigNumbers b("155");
	BigNumbers c = a * b;
	bool greater = a < b;
	cout << static_cast<string>(c) << endl;
	cout << greater << endl;
	return 0;
}

