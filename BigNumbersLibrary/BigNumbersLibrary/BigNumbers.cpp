//Fadhar Jared Castillo
//CS 256 C++ Programming
//Final Part 1: BigNumbersLibrary

#include "stdafx.h"
#include "BigNumbers.h"

/**Constructor: BigNumbers
*Usage: BigNumbers bigNum;
*Creates a BigNumbers object that behaves like 0.
*/
BigNumbers::BigNumbers()
{
	isNegative = false;
	digits.push_back(0);
	strDigits = "0";
}

/**Constructor: BigNumbers
*Usage: BigNumbers bigNum("-43243243223423432"), bigNum2("550533");
*Creates a BigNumbers object from a std::string representing a list
*of digits.
*/
BigNumbers::BigNumbers(const std::string& number)
{
	//Insert all the numerical digits to the vector
	if (number[0] == '-')
	{
		isNegative = true;
		for (int i = 1; i < number.size(); i++)
		{
			digits.push_back((number[i] - '0') % 48);
			strDigits.push_back(number[i]);
		}
	}
	else
	{
		isNegative = false;
		for (int i = 0; i < number.size(); i++)
		{
			digits.push_back((number[i] - '0') % 48);
			strDigits.push_back(number[i]);
		}
	}
	removeLeadingZeros();
	//Check if this is zero, if so, verify it is not negative
	if (digits[0] == 0)
	{
		isNegative = false;
	}
}

/**Operator: std::string
*Usage: cout << static_cast<string>(bigNum);
*Converts the BigNumbers to an std::string.
*/
BigNumbers::operator std::string() const
{
	std::string result;
	if (isNegative)
	{
		result.push_back('-');
	}

	for (int i = 0; i < digits.size(); i++)
	{
		result.push_back(digits[i] + '0');
	}
	return result;
}
/**Operator: +
*Usage: BigNumbers result = bigNum1 + bigNum2;
*Adds two BigNumbers objects and returns the result as a BigNumbers object.
*/
BigNumbers BigNumbers::operator+(const BigNumbers& bigNumber)
{
	BigNumbers lhsPos(strDigits), rhsPos(bigNumber.strDigits);
	if (isNegative && !bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = subtract(lhsPos.digits, rhsPos.digits);
			result.isNegative = true;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = subtract(rhsPos.digits, lhsPos.digits);
			result.isNegative = false;
			return result;
		}
		//Numbers are equal return zero
		else
		{
			BigNumbers result;
		}
	}
	else if (!isNegative && bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = subtract(lhsPos.digits, rhsPos.digits);
			result.isNegative = false;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = subtract(rhsPos.digits, lhsPos.digits);
			result.isNegative = true;
			return result;
		}
		else
		{
			BigNumbers result;
		}
	}
	else
	{
		BigNumbers result = add(lhsPos.digits, rhsPos.digits);
		result.isNegative = false;
		return result;
	}
}

/**Operator: -
*Usage: BigNumbers result = bigNum1 - bigNum2;
*Subtracts two BigNumbers objects and returns the result as a BigNumbers object.
*/
BigNumbers BigNumbers::operator-(const BigNumbers& bigNumber)
{
	BigNumbers lhsPos(strDigits), rhsPos(bigNumber.strDigits);
	if (isNegative && !bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos) || lhsPos.operator<(rhsPos))
		{
			BigNumbers result = add(lhsPos.digits, rhsPos.digits);
			result.isNegative = true;
			return result;
		}
		//Numbers are equal return zero
		else
		{
			BigNumbers result;
		}
	}
	else if (!isNegative && bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos) || lhsPos.operator<(rhsPos))
		{
			BigNumbers result = add(lhsPos.digits, rhsPos.digits);
			result.isNegative = false;
			return result;
		}
		else
		{
			BigNumbers result;
		}
	}
	else if (!isNegative && !bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = subtract(lhsPos.digits, rhsPos.digits);
			result.isNegative = false;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = subtract(rhsPos.digits, lhsPos.digits);
			result.isNegative = true;
			return result;
		}
	}
	else if (isNegative && bigNumber.isNegative)
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = subtract(lhsPos.digits, rhsPos.digits);
			result.isNegative = true;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = subtract(rhsPos.digits, lhsPos.digits);
			result.isNegative = false;
			return result;
		}
	}
}
/**Operator: *
*Usage: BigNumbers result = bigNum1 * bigNum2;
*Multiplies two BigNumbers objects and returns the result as a BigNumbers object
*/
BigNumbers BigNumbers::operator*(const BigNumbers& bigNumber)
{
	BigNumbers lhsPos(strDigits), rhsPos(bigNumber.strDigits);
	if ((isNegative && !bigNumber.isNegative) || (!isNegative && bigNumber.isNegative))
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = multiply(digits, bigNumber.digits);
			result.isNegative = true;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = multiply(bigNumber.digits, digits);
			result.isNegative = true;
			return result;
		}
	}
	else
	{
		if (lhsPos.operator>(rhsPos))
		{
			BigNumbers result = multiply(digits, bigNumber.digits);
			result.isNegative = false;
			return result;
		}
		else if (lhsPos.operator<(rhsPos))
		{
			BigNumbers result = multiply(bigNumber.digits, digits);
			result.isNegative = false;
			return result;
		}
	}
}
/**Operator: /
*Usage: BigNumbers result = bigNum1 / bigNum2;
*Divides two BigNumbers objects and returns the result as a BigNumbers object
*	Not intended to be used as float or double
*   Throws DivisionByZeroException if the divisor is zero
*/
BigNumbers BigNumbers::operator/(const BigNumbers& bigNumber) throw()
{
	BigNumbers zero;
	if (bigNumber == zero)
	{
		//Trying to divide by zero
		throw DivisionByZeroException();
	}
	else
	{
		BigNumbers lhsPos(strDigits), rhsPos(bigNumber.strDigits);
		if (lhsPos.operator<(rhsPos))
		{
			//Return zero
			BigNumbers d;
			return d;
		}
		else if (lhsPos.operator==(rhsPos))
		{
			BigNumbers d("1");
			return d;
		}
		else
		{
			BigNumbers quotient = divide(lhsPos, rhsPos, 0);
			if ((isNegative && !bigNumber.isNegative) || (!isNegative && bigNumber.isNegative))
			{
				quotient.isNegative = true;
			}
			else
			{
				quotient.isNegative = false;
			}
			return quotient;
		}
	}
}
/**Operator: %
*Usage: BigNumbers result = bigNum1 % bigNum2;
*Computes the remainder of two BigNumbers objects and returns the result as a BigNumbers object
*/
BigNumbers BigNumbers::operator%(const BigNumbers& bigNumber)
{
	BigNumbers zero;
	if (bigNumber == zero)
	{
		//Trying to divide by zero
		throw DivisionByZeroException();
	}
	else
	{
		BigNumbers lhsPos(strDigits), rhsPos(bigNumber.strDigits);
		if (lhsPos.operator<(rhsPos))
		{
			//Return a copy of this
			return lhsPos;
		}
		else if (lhsPos.operator==(rhsPos))
		{
			BigNumbers d("1");
			return d;
		}
		else
		{
			BigNumbers remainder = divide(lhsPos, rhsPos, 1);
			if ((isNegative && !bigNumber.isNegative) || (!isNegative && !bigNumber.isNegative))
			{
				remainder.isNegative = false;
			}
			else
			{
				remainder.isNegative = true;
			}
			return remainder;
		}
	}
}

/**Operator: >
*Usage: bool isBigger = bigNum1 > bigNum2;
*Compares the left hand bigNum1 to right hand bigNumb2 and determines if
*	bigNum1 is greater than bigNum2
*/
bool BigNumbers::operator>(const BigNumbers& bigNumber) const
{
	if (isNegative && !bigNumber.isNegative)
	{
		return false;
	}
	else if (!isNegative && bigNumber.isNegative)
	{
		return true;
	}
	else if (!isNegative && !bigNumber.isNegative)
	{
		if (digits.size() > bigNumber.digits.size())
		{
			return true;
		}
		else if (digits.size() == bigNumber.digits.size())
		{
			int firstNonEqualDigit = 0;
			//Find first non zero digit, save its location
			for (int i = 0; i < digits.size() - 1; i++)
			{
				if (digits[i] == bigNumber.digits[i])
				{
					firstNonEqualDigit++;
				}
				else
				{
					i = digits.size();
				}
			}
			if (digits[firstNonEqualDigit] > bigNumber.digits[firstNonEqualDigit])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (isNegative && bigNumber.isNegative)
	{
		if (digits.size() > bigNumber.digits.size())
		{
			return false;
		}
		else if (digits.size() == bigNumber.digits.size())
		{
			int firstNonEqualDigit = 0;
			//Find first non zero digit, save its location
			for (int i = 0; i < digits.size() - 1; i++)
			{
				if (digits[i] == bigNumber.digits[i])
				{
					firstNonEqualDigit++;
				}
				else
				{
					i = digits.size();
				}
			}
			if (digits[firstNonEqualDigit] > bigNumber.digits[firstNonEqualDigit])
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
}
/**Operator: <
*Usage: bool isSmaller = bigNum1 < bigNum2;
*Compares the left hand bigNum1 to right hand bigNumb2 and determines if
*	bigNum1 is smaller than bigNum2
*/
bool BigNumbers::operator<(const BigNumbers& bigNumber) const
{
	if (isNegative && !bigNumber.isNegative)
	{
		return true;
	}
	else if (!isNegative && bigNumber.isNegative)
	{
		return false;
	}
	else if (!isNegative && !bigNumber.isNegative)
	{
		if (digits.size() < bigNumber.digits.size())
		{
			return true;
		}
		else if (digits.size() == bigNumber.digits.size())
		{
			int firstNonEqualDigit = 0;
			//Find first non zero digit, save its location
			for (int i = 0; i < digits.size() - 1; i++)
			{
				if (digits[i] == bigNumber.digits[i])
				{
					firstNonEqualDigit++;
				}
				else
				{
					i = digits.size();
				}
			}
			if (digits[firstNonEqualDigit] < bigNumber.digits[firstNonEqualDigit])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (isNegative && bigNumber.isNegative)
	{
		if (digits.size() > bigNumber.digits.size())
		{
			return true;
		}
		else if (digits.size() == bigNumber.digits.size())
		{
			int firstNonEqualDigit = 0;
			//Find first non zero digit, save its location
			for (int i = 0; i < digits.size() - 1; i++)
			{
				if (digits[i] == bigNumber.digits[i])
				{
					firstNonEqualDigit++;
				}
				else
				{
					i = digits.size();
				}
			}
			if (digits[firstNonEqualDigit] < bigNumber.digits[firstNonEqualDigit])
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

bool BigNumbers::operator==(const BigNumbers& bigNumber) const
{
	if (this->operator>(bigNumber) || this->operator<(bigNumber))
	{
		return false;
	}
	else
	{
		return true;
	}
}

BigNumbers BigNumbers::add(std::vector<int> lhs, std::vector<int> rhs)
{
	std::stack<int> result;

	int carry = 0, sum = 0, lhsIndex = lhs.size() - 1,
		rhsIndex = rhs.size() - 1;
	//Do until one of the vectors does not have any digits left
	while (lhsIndex >= 0 && rhsIndex >= 0)
	{
		//Add two digits and carry
		sum = lhs[lhsIndex] + rhs[rhsIndex] + carry;
		//Calculate the carry
		carry = sum / 10;
		sum = sum % 10;

		//Add sum to result vector
		result.push(sum);

		//Decrease the counters for next digit
		lhsIndex--;
		rhsIndex--;
	}
	if (rhsIndex >= 0 && lhsIndex < 0)
	{
		while (rhsIndex >= 0)
		{
			result.push(rhs[rhsIndex] + carry);
			rhsIndex--;
			carry = 0;
		}
	}
	//Right hand side does not have any more digits, but left hand side does
	if (lhsIndex >= 0 && rhsIndex < 0)
	{
		while (lhsIndex >= 0)
		{
			result.push(lhs[lhsIndex] + carry);
			lhsIndex--;
			carry = 0;
		}
	}
	if (carry != 0)
	{
		result.push(carry);
	}

	//result is backwards, reverse the digits and return new BigNumbers object
	return BigNumbers(result);
}
BigNumbers BigNumbers::subtract(std::vector<int> lhs, std::vector<int> rhs)
{
	std::stack<int> result;

	int borrow = 0, subtraction = 0, lhsIndex = lhs.size() - 1,
		rhsIndex = rhs.size() - 1;
	//Do until rhs does not have any digits left
	while (lhsIndex >= 0 && rhsIndex >= 0)
	{
		//Subtract
		subtraction = lhs[lhsIndex] - rhs[rhsIndex] - borrow;
		//Determine if there is borrow
		if (subtraction < 0)
		{
			borrow = 1;
			subtraction = subtraction + 10;
		}
		else
		{
			borrow = 0;
		}

		//Add subtraction to result vector
		result.push(subtraction);

		//Decrease the counters for next digit
		lhsIndex--;
		rhsIndex--;
	}

	//Right hand side does not have any more digits, but left hand side does
	if (lhsIndex >= 0 && rhsIndex < 0)
	{
		while (lhsIndex >= 0)
		{
			subtraction = lhs[lhsIndex] - borrow;
			//Determine if there is borrow
			if (subtraction < 0)
			{
				borrow = 1;
				subtraction = subtraction + 10;
			}
			else
			{
				borrow = 0;
			}

			//Add subtraction to result vector
			result.push(subtraction);
			lhsIndex--;
		}
	}

	//result is backwards, reverse the digits and return new BigNumbers object
	return BigNumbers(result);
}

BigNumbers BigNumbers::multiply(std::vector<int> lhs, std::vector<int> rhs)
{
	std::stack<int> resultStack;
	std::stack<BigNumbers> bigNumbersStack;
	int carry = 0, product = 0, lhsIndex = lhs.size() - 1, rhsIndex = rhs.size() - 1;
	int iterations = 0;
	while (rhsIndex >= 0)
	{
		//Multiply the first stack
		product = lhs[lhsIndex] * rhs[rhsIndex] + carry;
		//Calculate the carry
		carry = product / 10;
		//Get the single digit remainder
		product = product % 10;
		//Add the product to the stack
		resultStack.push(product);
		//Decrease index to next digit to be processed
		lhsIndex--;
		//If the first Stack is empty but the second stack is not empty,
		if (lhsIndex < 0)
		{
			//reset the index
			lhsIndex = lhs.size() - 1;
			//If carry is not zero, push it on the stack
			if (carry != 0)
			{
				resultStack.push(carry);
			}
			//Reset carry
			carry = 0;
			//Create a BigNumbers from this multiplication
			BigNumbers b(resultStack);
			//Store it so that all the multiplicaitons can be added together
			bigNumbersStack.push(b);
			//Decrease index to nex
			rhsIndex--;
			iterations++;

			//If there are still digits to multiply
			if (rhsIndex >= 0)
			{
				//Remove everything from the stack
				while (!resultStack.empty())
				{
					resultStack.pop();
				}
				//Add the corresponding number of zeros to the next line
				for (int i = 0; i < iterations; i++)
				{
					resultStack.push(0);
				}
			}
		}
	}
	//Add all the rows multiplications
	BigNumbers result;
	while (!bigNumbersStack.empty())
	{
		result = result + bigNumbersStack.top();
		bigNumbersStack.pop();
	}
	return result;
}

BigNumbers BigNumbers::divide(BigNumbers lhs, BigNumbers rhs, int mode)
{
	BigNumbers counter;
	BigNumbers one("1");
	while (lhs > rhs)
	{
		lhs = lhs - rhs;
		counter = counter + one;
	}
	if (mode = 0) {
		return counter;
	}
	else
	{
		return lhs;
	}
}
void BigNumbers::removeLeadingZeros()
{
	int firstNonZeroDigit = 0;
	//Find first non zero digit, save its location
	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] == 0)
		{
			firstNonZeroDigit++;
		}
		else
		{
			i = digits.size();
		}
	}
	//Remove the zeros
	for (int i = 0; i < firstNonZeroDigit; i++)
	{
		digits.erase(digits.begin());
		strDigits.erase(strDigits.begin());
	}
}
/*Helper constructor: BigNumbers*/
BigNumbers::BigNumbers(std::stack<int>& stackInt)
{
	while (!stackInt.empty())
	{
		digits.push_back(stackInt.top());
		strDigits.push_back(stackInt.top() + '0');
		stackInt.pop();
	}
	removeLeadingZeros();
}
