/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : LUKE MASON
 * Student Number   : s3630120
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include <stdio.h>
#include "reversi.h"

/**
 * the hear of the program. The main() function in particular should 
 * manage the main menu for the program.
 **/
int main(void)
{
    score scrboard[MAX_SCORES];
	struct player player1, player2, *winner = NULL;
	char choice[3];
	long intchoice;
	char* end;
    /* initialise the scoreboard */
	init_scoreboard(scrboard);
    /* in a loop: display the main menu */
	printf("Welcome to Reversi!\n");
	printf("===================\n");
do
{	
	printf("Select an option:\n");
	printf("1. Play a game\n");
	printf("2. Display High Scores\n");
	printf("3. Quit the program\n");
	printf("Please enter your choice: >> ");
    /* get the user's selection from the main menu */
	fgets(choice,sizeof(choice),stdin);
	intchoice = strtol(choice,&end, 10);	
	if(choice[strlen(choice)-1] == '\n')/*checking for buffer overflow*/
	{
		switch(intchoice)
		{
			case 1 :winner = play_game(&player1,&player2); 
					if(winner != NULL)
					{
						add_to_scoreboard(scrboard, winner);
					}
					break; 
			case 2 :display_scores(scrboard) ; break;
			case 3 : printf("Quitting the program!\n"); break;
			default : printf("Invalid option please try again, choose 1, 2 or 3 only\n"); break;
		}
	}
	else
	{
		printf("Invalid option, Line too long, please enter a single digit, either 1,2 or 3\n");
		read_rest_of_line();
	}
}
while (intchoice != 3);
    /* perform the requested task */
            /* play a game and add the winner to the scoreboard */    
        
            /* display scores */
            /* quit the program */
    return EXIT_SUCCESS;
}

