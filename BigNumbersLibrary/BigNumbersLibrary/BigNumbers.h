#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <stack>

/**
* BigNumbers Class allows for storage of integer numbers
* of exceedingly many digits. This class also allows for basic
* arithmetic operations such as addition, subtraction, multiplication, etc.
*/
class BigNumbers
{
private:
	///Stores individual integer digits
	std::vector<int> digits;
	///Stores individual character representation of the digits
	std::string strDigits;
	///Internal variable that allows to determine if the BigNumber is negative.
	bool isNegative;
	///Private helper constructor
	BigNumbers(std::stack<int>& stackInt);
	///Private helper function that performs subtraction
	BigNumbers subtract(std::vector<int> lhs, std::vector<int> rhs);
	///Private helper function that performs addition
	BigNumbers add(std::vector<int> lhs, std::vector<int> rhs);
	///Private helper function that performs multiplication
	BigNumbers multiply(std::vector<int> lhs, std::vector<int> rhs);
public:
	/**Constructor: BigNumbers
	*Usage: BigNumbers bigNum;
	*Creates a BigNumbers object that behaves like 0.
	*/
	BigNumbers();
	/**Constructor: BigNumbers
	*Usage: BigNumbers bigNum("43243243223423432");
	*Creates a BigNumbers object from a std::string representing a list
	*of digits.
	*/
	BigNumbers(const std::string& number);

	/**Operator: std::string
	*Usage: cout << static_cast<string>(bigNum);
	*Converts the BigNumbers to an std::string.
	*/
	operator std::string() const;
	/**Operator: +
	*Usage: BigNumbers result = bigNum1 + bigNum2;
	*Adds two BigNumbers objects and returns the result as a BigNumbers object.
	*/
	BigNumbers operator+(const BigNumbers& bigNumber);
	/**Operator: -
	*Usage: BigNumbers result = bigNum1 - bigNum2;
	*Subtracts two BigNumbers objects and returns the result as a BigNumbers object.
	*/
	BigNumbers operator-(const BigNumbers& bigNumber);
	/**Operator: *
	*Usage: BigNumbers result = bigNum1 * bigNum2;
	*Multiplies two BigNumbers objects and returns the result as a BigNumbers object
	*/
	BigNumbers operator*(const BigNumbers& bigNumber);
	/**Operator: /
	*Usage: BigNumbers result = bigNum1 / bigNum2;
	*Divides two BigNumbers objects and returns the result as a BigNumbers object
	*	Not intended to be used as float or double
	*/
	BigNumbers operator/(const BigNumbers& bigNumber);
	/**Operator: %
	*Usage: BigNumbers result = bigNum1 % bigNum2;
	*Computes the remainder of two BigNumbers objects and returns the result as a BigNumbers object
	*/
	BigNumbers operator%(const BigNumbers& bigNumber);
	/**Operator: >
	*Usage: bool isBigger = bigNum1 > bigNum2;
	*Compares the left hand bigNum1 to right hand bigNumb2 and determines if
	*	bigNum1 is greater than bigNum2
	*/
	bool operator>(const BigNumbers& bigNumber) const;
	/**Operator: <
	*Usage: bool isSmaller = bigNum1 < bigNum2;
	*Compares the left hand bigNum1 to right hand bigNumb2 and determines if
	*	bigNum1 is smaller than bigNum2
	*/
	bool operator<(const BigNumbers& bigNumber) const;
};