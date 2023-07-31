/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by Paul Miller 
 **********************************************************************/
#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required 
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random 
 * number generator, that kind of thing. 
 *
 * Next, you should set the initial player - the initial player is the player 
 * whose token was set by initialisation to RED. 
 *
 * Next, you will need to manage the game loop in here. In each loop of the 
 * game, you should display the game board, including player scores 
 * display whose turn it is, etc in the format specified in the assignment
 * specification. Finally at the end of each turn you will calculate the score 
 * for each player you will calculate their score and store it and then you 
 * will need to swap the current player and other player 
 * using the swap_player() function. 
 * 
 * A game will end when either player presses enter or ctrl-d on a newline. 
 * 
 * When you detect a request to end the game, you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score.
 **/
struct player * play_game(struct player* first, struct player * second)
{
	BOOLEAN test;
	game_board board;
	enum cell token;
	struct player * current, *other, *winner;
	current = first;
	other = second;
	init_game_board(board);
	
	do
	{
		test = init_first_player(current,&token);
	}
	while( test == FALSE);
	if(test==2)
	{
		return NULL;
	}
	do
	{
		test = init_second_player(other, token);
	}
	while( test == FALSE);
	if(test==2)
	{
		return NULL;
	}
	if(current->token == BLUE)
	{
		swap_players(&current,&other);
	}
	
	do
	{
		do
		{
			display_board(board, current, other);
			test = make_move(current,board);
		}
		while(test == FALSE);
		current->score = game_score(board,current->token);
		swap_players(&current,&other);	
		current->score = game_score(board,current->token);
	}
	while(test <2);
	if(current->score > other->score)
	{
		winner = current;
		printf("\nThe Winner is %s\n\n",winner->name);
	}
	else if(current->score == other->score)
	{
		printf("\nThe Game is a tie!!\n\n");
		winner = NULL;
	}
	else
	{
		winner = other;
		printf("\nThe Winner is %s\n\n",winner->name);
	}
	return winner;
}

/**
 * does the work of applying the move requested by the user to the game board.
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured. If there are no pieces
 * that can be captured in any direction, it is an invalid move.
 **/
BOOLEAN apply_move(game_board board, unsigned y1, unsigned x1,
                   enum cell player_token)
{
	BOOLEAN north     = FALSE;
	BOOLEAN northEast = FALSE;
	BOOLEAN east      = FALSE;
	BOOLEAN southEast = FALSE;
	BOOLEAN south     = FALSE;
	BOOLEAN southWest = FALSE;
	BOOLEAN west      = FALSE;
	BOOLEAN northWest = FALSE;
	int y = y1;
	int x = x1;
	int player2_token;
	int i;
	int j;
	int k;
	int l;
	int p = 0;
	/*unsigned captured_pieces = 0;*/
	/*NORTH*/
	x = x - 1;
	y = y - 1;
	if(player_token == BLUE)
	{
		player2_token = 1;
	}
	else if(player_token == RED)
	{
		player2_token = 2;
	}
	else
	{
		printf("ERROR: Player 2 Token not found");
	}
	if(board[y][x] == BLANK)
	{
		if(y != 0 && board[y-1][x] == player2_token)
		{
			north = TRUE;
		}
		if(x != 0 && board[y][x-1] == player2_token)
		{
			west = TRUE;
		}
		if(y != 7 && board[y+1][x] == player2_token)
		{
			south = TRUE;
		}
		if(x != 7 && board[y][x+1] == player2_token)
		{
			east = TRUE;
		}
		if(x != 7 && y != 0)
		{
			if(board[y-1][x+1] == player2_token)
			{
				northEast = TRUE;
			}
		}
		if(x != 0 && y != 0)
		{
			if(board[y-1][x-1] == player2_token)
			{
				northWest = TRUE;
			}
		}
		if(x != 0 && y != 7)
		{
			if(board[y+1][x-1] == player2_token)
			{
				southWest = TRUE;
			}
		}
		if(x != 7 && y != 7)
		{
			if(board[y+1][x+1] == player2_token)
			{
				southEast = TRUE;
			}
		}
		if(north == TRUE)
		{
			for(i=y-2; i>=0; --i)
			{
				if(board[i][x] != BLANK)
				{
					if(board[i][x] == player_token)
					{
						for(j=i;j<=y; ++j)
						{
							board[j][x] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(east == TRUE)
		{
			for(i=x+2; i<8; ++i)
			{
				if(board[y][i] != BLANK)
				{
					if(board[y][i] == player_token)
					{
						for(j=i; j>=x; --j)
						{
							board[y][j] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(south == TRUE)
		{
			for(i = y+1; i<8; ++i)
			{
				if(board[i][x] != BLANK)
				{
					if(board[i][x] == player_token)
					{
						for(j=i; j>=y; --j)
						{	
								board[j][x] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(west == TRUE)
		{
			for(i = x-2; i>=0; --i)
			{
				if(board[y][i] != BLANK)
				{
					if(board[y][i] == player_token)
					{
						for(j=i; j<=x; ++j)
						{
							board[y][j] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(northEast == TRUE)
		{
			for(i=x+2, j=y-2; i<8 && j>=0; ++i, --j)
			{
				if(board[j][i] != BLANK)
				{
					if(board[j][i] == player_token)
					{
						for(k=i, l=j; k>=x && l<=y; --k, ++l)
						{
							board[l][k] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(southEast == TRUE)
		{
			for(i = x+2, j = y+2; i<8 && j<8; ++i, ++j)
			{
				if(board[j][i] != BLANK)
				{
					if(board[j][i] == player_token)
					{
						for(k=i, l=j; k>=x && l>=y; --k, --l)
						{
							board[l][k] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(southWest == TRUE)
		{
			for(i = x-2, j = y+2; i>=0 && j<8; --i, ++j)
			{
				if(board[j][i] != BLANK)
				{
					if(board[j][i] == player_token)
					{
						for(k=i, l=j; k<=x && l>=y; ++k, --l)
						{
							board[l][k] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if(northWest == TRUE)
		{
			for(i = x-2, j = y-2; i>=0 && j>=0; --i, --j)
			{
				if(board[j][i] != BLANK)
				{
					if(board[j][i] == player_token)
					{
						for(k=i, l=j; k<=x && j<=y; ++k, ++l)
						{
							board[l][k] = player_token;
						}
						++p;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	else
	{
		printf("\nNot A valid move, Try again\n\n\n");
		return FALSE;
	}
	if(p==0)
	{
		printf("\nNot A valid move, try again\n\n\n");
		return FALSE;
	}
	return TRUE;
}

/**
 * simply count up how many locations contain the player_token 
 * specified on the game_board.
 **/
unsigned game_score(game_board board, enum cell player_token)
{
	int count = 0;
	int i;
	int j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8; j++)
		{
			if(board[i][j] == player_token)
			{
				++count;
			}
		}
	}
	return count;
}

/**
 * swap the two player pointers passed in so that first points to the player
 * pointer that originally contained the second player and vice versa.
 **/
void swap_players(struct player ** first, struct player ** second)
{
	struct player * temp = *first;
    *first = *second;
    *second = temp;
}

