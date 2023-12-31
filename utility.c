/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/

#include "utility.h"

/**
 * function required to be used when clearing the buffer. It simply reads
 * each char from the buffer until the buffer is empty again. Please refer
 * to the materials on string and buffer handling in the course for more 
 * information.
 **/
void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != NEWLINE)
        ;
    clearerr(stdin);
}
INPUT_RESULT fgetsChecker(char* input,int inputsize)
{
	if(input[strlen(input)-1] != '\n')
	{
		printf("Error: too much data entered. Please try again.\n\n");
		read_rest_of_line();
		return 0;
	}
	input[strlen(input)-1]='\0';
	return 1;
}

