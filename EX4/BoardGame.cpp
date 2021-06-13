#include "BoardGame.h"

void BoardGame::printBoard(int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		cout << _board[i][j] << " ";
		cout << endl;
	}
}

