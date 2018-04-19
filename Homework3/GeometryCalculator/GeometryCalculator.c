/*
 * GeometryCalculator.c
 *
 *  Created on: Apr 17, 2018
 *  Author: Fadhar Jared Castillo
 *  Bronco#: 012546365
 *  Course: CS 256 C++ Programming
 *  Homework 3: Geometry Calculator
 */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int main(int argc, char **argv)
{
	double radius, length, width, base, height, answer;
	int choice;

	printf("1. Calculate the area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n\n");
	printf("Enter your choice (1-4):\n");

	fflush(stdout);
	scanf("%d", &choice);

	switch(choice)
	{
	case 1:
		printf("Enter the radius of the circle:\n");
		fflush(stdout);
		scanf("%lf", &radius);
		if(radius < 0)
		{
			printf("Only positive numbers please!\n");
		}
		else
		{
			answer = PI*radius*radius;
			printf("The area of the Circle: %lf:\n", answer);
		}
		break;
	case 2:
		printf("Enter the Length of the rectangle:\n");
		fflush(stdout);
		scanf("%lf", &length);
		printf("Enter the width of the rectangle:\n");
		fflush(stdout);
		scanf("%lf", &width);

		if(width < 0 || length < 0)
		{
			printf("Only positive numbers please!");
		}
		else
		{
			answer = length*width;
			printf("The area of the Rectangle: %lf:\n", answer);
		}
		break;
	case 3:
		printf("Enter the Base of the triangle:\n");
		fflush(stdout);
		scanf("%lf", &base);
		printf("Enter the Height of the triangle:\n");
		fflush(stdout);
		scanf("%lf", &height);

		if(base < 0 || height < 0)
		{
			printf("Only positive numbers please!");
		}
		else
		{
			answer = base*height*.5;
			printf("The area of the Triangle: %lf:\n", answer);
		}
		break;
	case 4:
		exit(0);
		break;
	default:
		printf("Sorry, not a valid input, please try again.\n");
		break;
	}

	return 0;
}

