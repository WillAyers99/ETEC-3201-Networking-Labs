//William Ayers

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lab5header.c"

int main ()
{
	int	board[BOARD_WIDTH][BOARD_HEIGHT];
    char input[11];
	init_board (board);     //initializes the board

	while(1)
    {
        print(board);
        printf("\nPress enter to continue or type quit/exit/q to quit: ");
        scanf("%[^\n]10s", input);      //Asks the user to enter an input that will determine the program behavior
        getchar();

        if ((input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't')
                || (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't')   //ends the program if the user types quit/exit/q
                || (input[0] == 'q')) exit(0);
        else
        {
            next_state(board);
        }
    }
}

void init_board (int board[][BOARD_HEIGHT])     //initializes the board to all zero values, then populates the board with living cells equal to STARTING_CELLS
{
	int	i, j, x, y;

	for (i=0; i < BOARD_WIDTH; i++)
    {
        for (j=0; j < BOARD_HEIGHT; j++)
		board[i][j] = 0;
    }
    i=0;
    while (i < STARTING_CELLS)
    {
        x = ((float)rand()/RAND_MAX) * BOARD_WIDTH;
        y = ((float)rand()/RAND_MAX) * BOARD_HEIGHT;
        if(board[x][y]==0)                               //picks a random spot on the board and if that spot is zero, it puts a one in its place
        {
            board[x][y] = 1;
            i++;
        }
    }
}

int xadd (int i, int a)     //increases the width index
{
	i += a;
	while (i < 0) i += BOARD_WIDTH;
	while (i >= BOARD_WIDTH) i -= BOARD_WIDTH;
	return i;
}

int yadd (int i, int a)     //increases the height index
{
	i += a;
	while (i < 0) i += BOARD_HEIGHT;
	while (i >= BOARD_HEIGHT) i -= BOARD_HEIGHT;
	return i;
}

int num_neighbors (int board[][BOARD_HEIGHT], int i, int j)     //Counts the number of living cells adjacent to the input cell
{
	int	k, l, count;

	count = 0;

	for (k=-1; k<=1; k++) for (l=-1; l<=1; l++)
    {
        if (k || l)
			if (board[xadd(i,k)][yadd(j,l)]) count++;
    }
	return count;
}

void next_generation(int newboard[][BOARD_HEIGHT], int board[][BOARD_HEIGHT])   //Determines the next generation after the current generation
{
    int	i, j, a;

	for (i=0; i<BOARD_WIDTH; i++) for (j=0; j<BOARD_HEIGHT; j++)
    {
		a = num_neighbors (board, i, j);
		if (a == 2) newboard[i][j] = board[i][j];
		if (a == 3) newboard[i][j] = 1;
		if (a < 2) newboard[i][j] = 0;
		if (a > 3) newboard[i][j] = 0;
	}
}

void next_state (int board[][BOARD_HEIGHT])     //advances the game to the next generation
{

	int	i, j, newboard[BOARD_WIDTH][BOARD_HEIGHT];

	next_generation(newboard, board);

	for (i=0; i<BOARD_WIDTH; i++) for (j=0; j<BOARD_HEIGHT; j++)
    {
		board[i][j] = newboard[i][j];
	}
}

void print (int board[][BOARD_HEIGHT])      //prints out the current generation
{
	int	i, j;

	for (j=0; j<BOARD_HEIGHT; j++)
    {
		for (i=0; i<BOARD_WIDTH; i++)
        {
			printf ("%c", board[i][j] ? '1' : '0');
		}
		printf ("\n");
	}
}
