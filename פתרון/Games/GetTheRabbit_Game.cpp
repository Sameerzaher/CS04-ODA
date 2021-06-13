#include "GetTheRabbit_Game.h"

#include <iostream>
using namespace std;

GetTheRabbit_Game::GetTheRabbit_Game(int steps, int x_player, int y_player, int x_comp, int y_comp) : Board(9, 9, 1, -1), steps(steps), x_player(x_player), y_player(y_player), x_comp(x_comp), y_comp(y_comp)
{
	matrix[x_comp][y_comp] = -1;
	matrix[x_player][y_player] = 1;
}

bool GetTheRabbit_Game::gameOver()
{
	return false;
}

bool GetTheRabbit_Game::checkWin(int val)
{
	if (val == player && x_comp == x_player && y_comp == y_player)
	{
		return true;
	}
	else if (val == computer && steps == 0)
	{
		return true;
	}
	return false;
}

bool GetTheRabbit_Game::play(int turn)
{
	int x = 0, y = 0;
	if (turn == computer)
	{
		return move('L', turn) || move('R', turn) || move('U', turn) || move('D', turn);
	}
	cout << "Please enter your move: L/R/U/D" << endl;
	char direction;
	cin >> direction;
	if (move(direction, turn))
	{
		steps--;
		return true;
	}
	return false;
}

bool GetTheRabbit_Game::move(char direction, int turn)
{
	int &x = turn == computer ? x_comp : x_player;
	int &y = turn == computer ? y_comp : y_player;
	int prev_x = x, prev_y = y;
	switch (direction)
	{
	case 'U':
		if (x == 0)
			return false;
		x--;
		break;
	case 'D':
		if (x == n)
			return false;
		x++;
		break;
	case 'L':
		if (y == 0)
			return false;
		y--;
		break;
	case 'R':
		if (y == m)
			return false;
		y++;
		break;
	default:
		return false;
	}
	if (matrix[x][y] != 0 && turn == computer)
	{
		x = prev_x;
		y = prev_y;
		return false;
	}
	matrix[prev_x][prev_y] = 0;
	matrix[x][y] = turn;
	return true;
}
