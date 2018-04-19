/*
 *  Population.c
 *
 *  Created on: Apr 17, 2018
 *  Author: Fadhar Jared Castillo
 *  Bronco#: 012546365
 *  Course: CS 256 C++ Programming
 *  Homework 3: Population
 */
#include <stdio.h>
#include <stdlib.h>

int calculateSize(int startingSize, double birthRate, double deathRate);

int main(int argc, char **argv)
{
	int startingSize, numberOfYears, oldPopulation, newPopulation;
	double birthRate, deathRate;

	printf("Population Calculator\n");
	printf("This program displays the estimated population based on\n");
	printf("The starting size of a population, the annual birth rate,\n");
	printf("the annual death rate and the number of years to display\n\n");

	do
	{
		printf("Enter the starting population:\n");
		fflush(stdout);
		scanf("%d", &startingSize);
		if(startingSize < 2)
		{
			printf("Please enter a positive number greater than 2.\n");
		}
	}while(startingSize < 2);

	do
	{
		printf("Enter the birth rate:\n");
		fflush(stdout);
		scanf("%lf", &birthRate);
		if(birthRate < 0)
		{
			printf("Please enter a positive number.\n");
		}
	}while(birthRate < 0);

	do
	{
		printf("Enter the death rate:\n");
		fflush(stdout);
		scanf("%lf", &deathRate);
		if(deathRate < 0)
		{
			printf("Please enter a positive number.\n");
		}
	}while(deathRate < 0);

	do
	{
		printf("Enter the number of years to display:\n");
		fflush(stdout);
		scanf("%d", &numberOfYears);
		if(numberOfYears < 0)
		{
			printf("Please enter a positive number.\n");
		}
	}while(numberOfYears < 0);

	oldPopulation = startingSize;
	for(int i = 0; i < numberOfYears; i++)
	{
		newPopulation = calculateSize(oldPopulation, birthRate, deathRate);
		printf("Population for Year %d: %d\n", i+1, newPopulation);
		oldPopulation = newPopulation;
	}
	return 0;
}

int calculateSize(int startingPopulation, double birthRate, double deathRate)
{
	return (startingPopulation + birthRate*startingPopulation - deathRate*startingPopulation);
}
