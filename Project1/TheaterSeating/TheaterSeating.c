/*
 * TheaterSeating.c
 *
 *  Author: Fadhar Jared Castillo
 *  Bronco#: 012546365
 *  Course: CS 256 C++ Programming
 *  Project 1: Theater Seating
 */

#include<stdio.h>
#include<stdlib.h>

#define SEAT_ROWS 15
#define SEATS_PER_ROW 30

double totalSales = 0.0;
char seats[SEAT_ROWS][SEATS_PER_ROW];
double pricePerRowArray[SEAT_ROWS];

void displaySeatingChart();
void displayStats();
void initializeArrayToEmptySeats();
void initializePricesPerRowArray();
int getMenuChoice();
int getRow();
int getSeatNumber();
int getNumberOfSeatsPurchased();
int validSeat(int row, int column);
int seatsAvailableInRow(int row);
int totalSeatsAvailable();
void sellSeats(int numberOfSeats, int row);

int main(int argc, char **argv)
{
	int row = -1, seatNumber = -1, numberOfSeats = 0, done = 0;

	//Initialize the array of seats to empty seats.
	initializeArrayToEmptySeats();
	initializePricesPerRowArray();

	displaySeatingChart();
	while(done == 0)
	{
		int menuChoice = getMenuChoice();
		switch(menuChoice)
		{
		case 1:
			numberOfSeats = getNumberOfSeatsPurchased();
			if(numberOfSeats > 1)
			{
				int seatsAvailable = 0;
				do
				{
					row = getRow();
					seatsAvailable = seatsAvailableInRow(row);
					if(seatsAvailable < numberOfSeats)
					{
						printf("Not enough seats available for this group.\n");
					}
					else
					{
						double sale = numberOfSeats*pricePerRowArray[row];
						totalSales += sale;
						sellSeats(numberOfSeats, row);
						printf("Total for %d seats %.2lf\n", numberOfSeats, sale);
					}
				} while(seatsAvailable < numberOfSeats);
			}
			else
			{
				do
				{
					row = getRow();
					seatNumber = getSeatNumber();
				} while(validSeat(row, seatNumber) == 0);
				seats[row][seatNumber] = '*';
				double sale = pricePerRowArray[row];
				totalSales += sale;
				printf("Total for seat %d in row %d: $%.2lf\n", seatNumber+1, row+1, sale);
			}
			displaySeatingChart();
			break;
		case 2:
			displayStats();
			break;
		case 3:
			exit(0);
			break;
		}
	}
	return 0;
}

void displaySeatingChart()
{
	printf("         ----------------------------------------Seats-------------------------------------------\n");
	printf("         1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
	for(int row = 1; row <= SEAT_ROWS; row++)
	{
		printf("Row %d:\t", row);
		for(int column = 1; column <= SEATS_PER_ROW; column++)
		{
			printf(" %c ", seats[row-1][column-1]);
		}
		printf("\n");
	}
}

void displayStats()
{
	int seatsAvailable = 0;
	for(int row = 0; row < SEAT_ROWS; row++)
	{
		int seatsAvailableRow = seatsAvailableInRow(row);
		printf("Seats available in row %d: %d\n", row+1, seatsAvailableRow);
		seatsAvailable += seatsAvailableRow;
	}
	printf("Total Seats available in Auditorium: %d\n", seatsAvailable);
	printf("Total Sales: $%.2lf\n", totalSales);
}
int getMenuChoice()
{
	int choice;
	do
	{
		printf("\nEnter your option:\n");
		printf("1. Purchase Tickets\n");
		printf("2. Show Statistics\n");
		printf("3. Exit Program\n");

		fflush(stdout);
		scanf("%d", &choice);

		if(choice > 3 || choice < 1)
		{
			printf("Please enter a valid number\n");
		}
	}while(choice > 3 || choice < 1);
	return (choice);
}

int getSeatNumber()
{
	int seat;
		do
		{
			printf("\nEnter the Seat Number:\n");
			fflush(stdout);
			scanf("%d", &seat);

			if(seat > 30 || seat < 1)
			{
				printf("Please enter a number in the range of 1 - 30\n");
			}
		}while(seat > 30 || seat < 1);
		return (seat - 1);
}

int getRow()
{
	int row;
	do
	{
		printf("\nEnter the Row:\n");
		fflush(stdout);
		scanf("%d", &row);

		if(row > 15 || row < 1)
		{
			printf("Please enter a number in the range of 1 - 15\n");
		}
	}while(row > 15 || row < 1);
	return (row - 1);
}

int getNumberOfSeatsPurchased()
{
	int numberOfSeats;
		do
		{
			printf("\nEnter the number of seats being purchased this transaction:\n");
			fflush(stdout);
			scanf("%d", &numberOfSeats);

			if(numberOfSeats > 30 ||  numberOfSeats< 1)
			{
				printf("Please enter a number in the range of 1 - 30\n");
			}
		}while(numberOfSeats > 30 ||  numberOfSeats< 1);
		return numberOfSeats;
}

int validSeat(int row, int seatNumber)
{
	if(seats[row][seatNumber] == '*')
	{
		printf("This seat is already booked! Try again!\n");
		return 0;
	}
	return 1;
}

void initializeArrayToEmptySeats()
{
	for(int row = 0; row < SEAT_ROWS; row++)
	{
		for(int seatNumber = 0; seatNumber < SEATS_PER_ROW; seatNumber++)
		{
			seats[row][seatNumber] = '#';
		}
	}
}
void initializePricesPerRowArray()
{
	for(int row = 0; row < SEAT_ROWS; row++)
	{
		double price = -0.1;
		do
		{
			printf("Enter price for Row %d:\n", (row + 1));
			fflush(stdout);
			scanf("%lf", &price);

			if(price <= 0.0)
			{
				printf("Please enter a valid price.\n");
			}
			else
			{
				pricePerRowArray[row] = price;
			}
		}while(price <= 0.0);
	}
}

int seatsAvailableInRow(int row)
{
	int seatCount = 0;
	for(int seatNumber = 0; seatNumber < SEATS_PER_ROW; seatNumber++)
	{
		if(seats[row][seatNumber] == '#')
		{
			seatCount++;
		}
	}
	return seatCount;
}

int totalSeatsAvailable()
{
	int totalSeats = 0;
	for(int row = 0; row < SEAT_ROWS; row++)
	{
		totalSeats += seatsAvailableInRow(row);
	}
	return totalSeats;
}

void sellSeats(int numberOfSeats, int row){
	for(int seatNumber = 0; seatNumber < SEATS_PER_ROW; seatNumber++)
	{
		if(numberOfSeats > 0 && seats[row][seatNumber] == '#')
		{
			seats[row][seatNumber] = '*';
			numberOfSeats--;
		}
		else if(numberOfSeats == 0){
			seatNumber = SEATS_PER_ROW;
		}
	}
}
