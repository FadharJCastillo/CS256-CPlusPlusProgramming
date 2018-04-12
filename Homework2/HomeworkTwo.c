/*
 * HomeworkTwo.c
 *
 *  Created on: Apr 11, 2018
 *      Author: Fadhar Jared Castillo
 *      Bronco#: 012546365
 *      Course: CS 256 C++ Programming
 *      Homework 2: Restaurant Bill,
 *      			Ocean Levels,
 *      			Stock Transaction Program
 *      			Pattern Displays
 */

#include <stdio.h>
#include <string.h>

void restaurantBill()
{
	const double taxPercent = 0.0675;
	const double tipPercent = 0.2;
	double mealCharge = 88.67;
	double taxAmount = mealCharge*taxPercent;
	double tipAmount = (mealCharge+taxAmount)*tipPercent;
	double totalBill = mealCharge+taxAmount+tipAmount;
	printf("\n---------Restaurant Bill---------------\n");
	printf("Meal Cost: %.2f\n", mealCharge);
	printf("Tax Amount: %.2f\n", taxAmount);
	printf("Tip Amount: %.2f\n", tipAmount);
	printf("Total Bill: %.2f\n",totalBill);
}

void oceanLevels()
{
	const double oceanRisingRate = 1.5;
	double oceanRisenIn5Years = oceanRisingRate*5;
	double oceanRisenIn7Years = oceanRisingRate*7;
	double oceanRisenIn10Years = oceanRisingRate*10;
	printf("\n---------Ocean Levels---------------\n");
	printf("The ocean will be %.2f millimeters higher in 5 years.\n", oceanRisenIn5Years);
	printf("The ocean will be %.2f millimeters higher in 7 years.\n", oceanRisenIn7Years);
	printf("The ocean will be %.2f millimeters higher in 10 years.\n", oceanRisenIn10Years);
}

void stockTransactionProgram()
{
	double purchasePricePerShare = 45.5, sellingPricePerShare = 56.9,
			commissionPercentage = 0.02;
	int numberOfShares = 1000;
	double amountPaidForStocks = purchasePricePerShare*numberOfShares;
	double purchaseCommission = amountPaidForStocks*commissionPercentage;
	double amountReceivedFromStocks = sellingPricePerShare*numberOfShares;
	double saleCommission = amountReceivedFromStocks*commissionPercentage;
	double profit = amountReceivedFromStocks-(amountPaidForStocks+purchaseCommission+saleCommission);

	printf("\n------Stock Transaction Program------\n");
	printf("The amount of money Joe paid for 1000 shares of stock: $%.2f\n", amountPaidForStocks);
	printf("Amount paid in commission to Joe's broker at purchase: $%.2f\n", purchaseCommission);
	printf("Amount received from selling the stocks: $%.2f\n", amountReceivedFromStocks);
	printf("Amount paid in commission to Joe's broker at sale: $%.2f\n", saleCommission);
	printf("Profit after commission: $%.2f \n", profit);
}

void patternDisplays()
{
	printf("\n-----Pattern Displays---------------\n");
	char pattern1[10] = "";
	char pattern2[] = "++++++++++";
	printf("Pattern A:\n");
	for(int i = 0; i <10; i++)
	{
		pattern1[i] = '+';
		printf("%s\n", pattern1);
	}
	printf("\n Pattern B: \n");
	for(int i = 10; i>=0; i--)
	{
		pattern2[i] = '\0';
		printf("%s\n",pattern2);
	}
}

int main(int argc, char **argv)
{
	restaurantBill();
	oceanLevels();
	stockTransactionProgram();
	patternDisplays();
	return 0;
}
