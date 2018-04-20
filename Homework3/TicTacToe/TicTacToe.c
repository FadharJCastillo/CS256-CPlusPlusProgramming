/*
 * TicTacToe.c
 *
 *  Created on: Apr 17, 2018
 *  Author: Fadhar Jared Castillo
 *  Bronco#: 012546365
 *  Course: CS 256 C++ Programming
 *  Homework 3: Tic-Tac-Toe
 */
#include <stdio.h>
#include <stdlib.h>

//FUNCTION PROTOTYPES
void displayBoard(char array[3][3]);
int getRow();
int getColumn();
int validMove(int xCoord, int yCoord, char array[3][3]);
int isWinner(char array[3][3]);
int checkHorizontals(char array[3][3]);
int checkVerticals(char array[3][3]);
int checkDiagonals(char array[3][3]);


int main(int argc, char **argv)
{
	char array[3][3];
	int xCoord, yCoord, finished = 0, turn = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = '*';
		}
	}

	printf("Welcome to Tic-Tac-Toe!\n");
	printf("Player 1: X's, Player 2: O's\n");

	while(finished != 1)
	{
		displayBoard(array);

		do
		{
		xCoord = getRow();
		yCoord= getColumn();
		} while(validMove(xCoord, yCoord, array) == 0);

		if(turn == 0)
		{
			array[xCoord][yCoord] = 'X';
			if(isWinner(array) == 1)
			{
				displayBoard(array);
				printf("PLAYER 1 WINS!\n");
				finished = 1;
			}
		}
		else if(turn == 1)
		{
			array[xCoord][yCoord] = 'O';
			if(isWinner(array) == 1)
			{
				displayBoard(array);
				printf("PLAYER 2 WINS!");
				finished = 1;
			}
		}

		turn = !turn;
	}
	return 0;
}


void displayBoard(char array[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("{ %c |  %c | %c }\n", array[i][0], array[i][1], array[i][2]);
	}
}
int getColumn()
{
	int xCoord;
	do
	{
		printf("\nEnter the Column:\n");
		fflush(stdout);
		scanf("%d", &xCoord);
		if(xCoord == -1)
		{
			printf("Thanks for playing!\n");
			exit(0);
		}
		else if(xCoord > 2 || xCoord <-1)
		{
			printf("Please enter a number in the range of 0 - 2\n");
		}
	}while(xCoord > 2 || xCoord < -1);
	return xCoord;
}

int getRow()
{
	int yCoord;
	do
	{
		printf("\nEnter the Row:\n");
		fflush(stdout);
		scanf("%d", &yCoord);
		if(yCoord == -1)
		{
			printf("Thanks for playing!\n");
			exit(0);
		}
		else if(yCoord > 2 || yCoord <-1)
		{
			printf("Please enter a number in the range of 0 - 2\n");
		}
	}while(yCoord > 2 || yCoord < -1);
	return yCoord;
}

int validMove(int xCoord, int yCoord, char array[3][3])
{
	if(array[xCoord][yCoord] == 'X' || array[xCoord][yCoord] == 'O')
	{
		printf("Invalid move! Try again!\n");
		return 0;
	}
	return 1;
}

int isWinner(char array[3][3])
{
	if(checkHorizontals(array) == 1 || checkVerticals(array) == 1 || checkDiagonals(array) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkHorizontals(char array[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		if ((array[i][0] == 'X' && array[i][1] == 'X' && array[i][2] == 'X') ||
				(array[i][0] == 'O' && array[i][1] == 'O' && array[i][2] == 'O'))
		{
			return 1;
		}
	}
	return 0;
}
int checkVerticals(char array[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		if ((array[0][i] == 'X' && array[1][i] == 'X' && array[2][i] == 'X') ||
				(array[0][i] == 'O' && array[1][i] == 'O' && array[2][i] == 'O'))
		{
			return 1;
		}
	}
	return 0;
}

int checkDiagonals(char array[3][3])
{
	if ((array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X') ||
		(array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


