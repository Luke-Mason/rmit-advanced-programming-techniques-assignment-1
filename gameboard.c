/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "gameboard.h"
#include "player.h"

/**
 * initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens
 **/
void init_game_board(game_board board)
{
	int i;
	int j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8; j++)
		{
			board[i][j] = BLANK;
		}
	}
	board[3][3] = RED;
	board[3][4] = BLUE;
	board[4][3] = BLUE;
	board[4][4] = RED;
}

/**
 * display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification. 
 **/
void display_board(game_board board, struct player * first,
                   struct player * second)
{	
	int i;
	int j;
	printf("==========================================================================================\n");
	printf("Player One's Details\n");
	printf("--------------------\n");
	printf("Name: %s       Score: %d       Token Colour: %s%c%s\n",first->name,first->score,(first->token == 1)? COLOR_RED:COLOR_BLUE,'0',COLOR_RESET);
	printf("------------------------------------------------------------------------------------------\n");
	printf("Player Two's Details\n");
	printf("--------------------\n");
	printf("Name: %s       Score: %d       Token Colour: %s%c%s\n",second->name,second->score,(second->token == 1)? COLOR_RED:COLOR_BLUE,'0',COLOR_RESET);
	printf("------------------------------------------------------------------------------------------\n");
	printf("     1   2   3   4   5   6   7   8  \n");
	printf("====================================\n");
	for(i=0;i<8;i++)
	{
		printf(" %d |",i+1);
			for(j=0; j<8; j++)
			{
				if(board[i][j] == RED)
				{
					printf(" %s%c%s |", COLOR_RED,'0',COLOR_RESET);
				}
				else if(board[i][j] == BLUE)
				{
					printf(" %s%c%s |", COLOR_BLUE,'0',COLOR_RESET);
				}
				else if(board[i][j] == BLANK)
				{
					printf("   |");
				}
				else
				{
					printf("ERR|");
				}
			}
		printf("\n------------------------------------\n");
	}
}

