
/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "player.h"
#include "game.h"
#include <stdlib.h>
#include <string.h>

/**
 * These two functions initialise the player structure at the beginning of the 
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the init_first_player() 
 * function you should then select a color at random for this player using the 
 * rand() function. This token should be assigned to the first player's token and
 * also returned via the token pointer. In init_second_player() you should just
 * test the value of token and assign the opposite color to the second player.
 **/                                      
BOOLEAN init_first_player(struct player* first, enum cell * token)
{
	int color;
	char name1[21];
	int checker;
	printf("Enter in player 1 name >> ");
	
	srand(time(NULL));
	color = rand() %2 + 1;
	*token = color;
	
	first->token = *token;
	first->score = 2;
	
	if(fgets(name1,21,stdin) == NULL)
    {
		printf("\n");
        return 2;
    }
	else if(name1[0] == '\n')
	{
		printf("\n");
		return 2;
	}
	else
	{
		checker = fgetsChecker(name1,21);
	}
	strcpy(first->name, name1);
	if(checker == 0)
	{
		return FALSE;
	}
	else if(checker == 1)
	{
		return TRUE;
	}
	return FALSE;
}

BOOLEAN init_second_player(struct player * second, enum cell token)
{
	char name2[21];
	int checker;
	second->score = 2;
	printf("Enter in player 2 name >> ");
	if(fgets(name2,21,stdin)== NULL)
    {
		printf("\n");
        return 2;
    }
	else if(name2[0] == '\n')
	{
		printf("\n");
		return 2;
	}
	else
	{
		checker = fgetsChecker(name2,21);
	}

	strcpy(second->name, name2);
	if(token == 1)
	{
		second->token = 2;
	}
	else if(token == 2)
	{
		second->token = 1;
	}
	else
	{
		printf("ERROR: Player 2 Token not 1 or 2, Try again\n");
		return FALSE;
	}
	if(checker == 0)
	{
		return FALSE;
	}
	else if(checker == 1)
	{
		return TRUE;
	}
	return FALSE;
}

/**
 * prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by 
 * surrounding a sequence of one or more enemy pieces with two pieces of our 
 * own: one being the new piece to be placed and the other a piece already 
 * on the board. This function then validates that a valid move has been entered
 * calls the apply_move function to do the actual work of capturing pieces.
 **/
BOOLEAN make_move(struct player * human, game_board board)
{
	char move[5];
	char* end;
	char* end2;
	char* tok;
	char* tok2;
	int x;
	int y;
	int checker;
	printf("It is %s's turn.\n",human->name);
	printf("Please enter x and y coordinates separated by a comma for the piece you wish to place: ");
	if(fgets(move,5,stdin)==NULL)
    {
		printf("\n");
        return 2;
    }
	else if(move[0] == '\n')
	{
		printf("\n");
		return 2;
	}
	else
	{
		checker = fgetsChecker(move,5);
	}
	if(checker == 0)
	{
		return FALSE;
	}

	if (move[1] != ',' || strlen(move) != 3)
	{
		printf("\n\nERROR: Invalid Co-ordinates\n");
		return FALSE;
	}

	tok = strtok(move, ","); /*Getting first number*/
	
	x = strtol(tok, &end, 10); /*Converting to int*/
	
	tok2 = strtok(NULL, ",");    /*Getting second number*/
	
	y = strtol(tok2, &end2, 10);   /*Converting to int*/
	
	if (tok == end || tok2 == end2)
	{
		printf("ERROR: co-ordinates are not numerical\n");
		return FALSE;
	}
	if(apply_move(board,y, x, human->token)==FALSE)
	{
		return FALSE;
	}
	return TRUE;
}