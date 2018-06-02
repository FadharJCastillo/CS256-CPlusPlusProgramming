//Fadhar Jared Castillo
//CS 256 C++ Programming
//Final Part 1: BigNumbersLibrary

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
	///Private helper function that performs division and modulo
	///To return the quotient, pass mode = 0. To return remainder pass mode = 1.
	BigNumbers divide(BigNumbers lhs, BigNumbers rhs, int mode);
	///Private helper method that removes the leading zeros from inputted digits
	///Example "000056785" becomes 56785 after execution
	void removeLeadingZeros();
public:
	/**Constructor: BigNumbers
	*Usage: BigNumbers bigNum;
	*Creates a BigNumbers object that behaves like 0.
	*/
	BigNumbers();
	/**Constructor: BigNumbers
	*Usage: BigNumbers bigNum("43243243223423432");
	*Creates a BigNumbers object from a std::string representing a list
	* of digits. To construct a negative number, the '-' symbol must be used
	* before the digits. To construct a positive number, no '+' symbol is needed.
	* if it is used, unexpected results may occur.
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
	*Usage: try{BigNumbers result = bigNum1 / bigNum2;}catch(BigNumbers::DivisionByZeroException){...}
	*Divides two BigNumbers objects and returns the result as a BigNumbers object
	*   Throws DivisionByZeroException if the divisor is zero.
	*/
	BigNumbers operator/(const BigNumbers& bigNumber) throw();
	/**Operator: %
	*Usage: try{BigNumbers result = bigNum1 % bigNum2;}catch(BigNumbers::DivisionByZeroException){...};
	*Computes the remainder of two BigNumbers objects and returns the result as a BigNumbers object
	*   Throws DivisionByZeroException if the divisor is zero
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
	/**Operator: ==
	*Usage: if(bigNum1 == bigNum2) ...
	*Compares the left hand bigNum1 to right hand bigNumb2 and determines if
	*	bigNum1 is equal to bigNum2
	*/
	bool operator==(const BigNumbers& bigNumber) const;

	/**class DivisionByZeroException
	*An instance of this class may be returned by the division and remainder operators.
	*/
	class DivisionByZeroException {};
};