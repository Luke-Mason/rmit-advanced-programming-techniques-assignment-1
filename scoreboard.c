/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "scoreboard.h"

/**
 * initalise the scoreboard so that the scores for each element of the array
 * is set to 0.
 **/
void init_scoreboard(score scores[MAX_SCORES])
{
	int i;
	for(i=0; i <=MAX_SCORES; ++i)
	{
		scores[i].score = 0;
		strcpy(scores[i].name,"");
	}
}


/**
 * insert the top scorer from the last game played in sorted order according
 * to their score 
 **/
BOOLEAN add_to_scoreboard(score scores[MAX_SCORES], struct player * winner)
{
	int i; 
	int j;
	int score = winner->score;
	char* name = winner->name;
	for(i=1; i<=MAX_SCORES; ++i)
	{		
		if(score > scores[i-1].score)
		{
			for(j=10; j>=i; --j)
			{
				/*printf("array[%d] is equal to array[%d]\n",j,j-1);
				printf("making %d equal to %d\n",scores[j].score,scores[j-1].score);*/
				scores[j-1].score = scores[j-2].score;
				strcpy(scores[j-1].name, scores[j-2].name);
			}
			scores[i-1].score = score;
			strcpy(scores[i-1].name, name);
			break;
		}
	}
	return FALSE;
}

/**
 * display the scores in the scoreboard according to their order. Your output
 * should match that provided in the assignment specification.
 **/
void display_scores(score scores[MAX_SCORES])
{
	int i;
	printf("\n                   Reversi - Top Scores\n");
	printf("==========================================================\n");
	printf("----------------------------------------------------------\n");
	printf(" #  | Name                 | Score\n");
	printf("----------------------------------------------------------\n");
	for(i = 1; i<=MAX_SCORES; ++i)
	{
	printf(" %-2d - %-20s | %d \n",i,scores[i-1].name,scores[i-1].score);
	}
	printf("----------------------------------------------------------\n");
}
