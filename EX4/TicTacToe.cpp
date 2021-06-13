#include "TicTacToe.h"

TicTacToe::TicTacToe() : BoardGame(3, 3)
{
	Rest();
}
void TicTacToe::console(const Move &move)
{

	performPlayerMove(move);
	if (getGameState() == InProgress)
		computerNextAIMove();
}
void TicTacToe::Rest()
{
	_board.clear();
	vector<char> temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			temp.push_back('-');
		_board.push_back(temp);
		temp.clear();
	}
}
void TicTacToe::performPlayerMove(const Move &move)
{

	if (move.getX() < 0 || move.getX() >= 3 || move.getY() < 0 || move.getY() >= 3 || _board[move.getX()][move.getY()] != '-')
		throw string("Invalid Move\nTry again\n");
	_board[move.getX()][move.getY()] = 'X';
}

GameState TicTacToe::getGameState() const
{
	for (int i = 0; i < 3; i++)
	{
		if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2] && _board[i][0] != '-')
			if (_board[i][0] == 'X')
				return PlayWins;
			else
				return ComputerWins;
	}

	for (int i = 0; i < 3; i++)
	{
		if (_board[0][i] == _board[1][i] && _board[1][i] == _board[2][i] && _board[0][i] != '-')
			if (_board[0][i] == 'X')
				return PlayWins;
			else
				return ComputerWins;
	}

	if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2] && _board[0][0] != '-')
		if (_board[0][0] == 'X')
			return PlayWins;
		else
			return ComputerWins;
	if (_board[2][0] == _board[1][1] && _board[1][1] == _board[0][2] && _board[2][0] != '-')
		if (_board[2][0] == 'X')
			return PlayWins;
		else
			return ComputerWins;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (_board[i][j] == '-')
				return InProgress;
	}

	return Tie;
}
void TicTacToeRand::computerNextAIMove()
{
	bool b = true;
	do
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (_board[x][y] == '-')
		{
			_board[x][y] = 'O';
			b = false;
		}
	} while (b);
}

void TicTacToeEdu::computerNextAIMove()
{
	char checkP = 'O';
	for (int i = 0; i < 2; i++)
	{
		if (((_board[0][0] == checkP && _board[0][1] == checkP) || (_board[2][2] == checkP && _board[1][2] == checkP) || (_board[2][0] == checkP && _board[1][1] == checkP)) && _board[0][2] == '-')
		{
			_board[0][2] = 'O';
			return;
		}
		else if (_board[0][1] == '-' && ((_board[0][0] == checkP && _board[0][2] == checkP) || (_board[1][1] == checkP && _board[2][1] == checkP)))
		{
			_board[0][1] = 'O';
			return;
		}
		else if (_board[0][0] == '-' && ((_board[0][2] == checkP && _board[0][1] == checkP) || (_board[1][0] == checkP && _board[2][0] == checkP) || (_board[2][2] == checkP && _board[1][1] == checkP)))
		{
			_board[0][0] = 'O';
			return;
		}
		else if (_board[1][2] == '-' && ((_board[0][2] == checkP && _board[2][2] == checkP) || (_board[1][0] == checkP && _board[1][1] == checkP)))
		{
			_board[1][2] = 'O';
			return;
		}
		else if (_board[1][1] == '-' && ((_board[0][0] == checkP && _board[2][2] == checkP) || (_board[2][0] == checkP && _board[0][2] == checkP) || (_board[0][1] == checkP && _board[2][1] == checkP) || (_board[1][0] == checkP && _board[1][2] == checkP)))
		{
			_board[1][1] = 'O';
			return;
		}
		else if (_board[1][0] == '-' && ((_board[0][0] == checkP && _board[2][0] == checkP) || (_board[1][1] == checkP && _board[1][2] == checkP)))
		{
			_board[1][0] = 'O';
			return;
		}
		else if (_board[2][2] == '-' && ((_board[0][2] == checkP && _board[1][2] == checkP) || (_board[2][0] == checkP && _board[2][1] == checkP)))
		{
			_board[2][2] = 'O';
			return;
		}
		else if (_board[2][1] == '-' && ((_board[2][0] == checkP && _board[2][2] == checkP) || (_board[0][1] == checkP && _board[1][1] == checkP)))
		{
			_board[2][1] = 'O';
			return;
		}
		else if (_board[2][0] == '-' && ((_board[0][0] == checkP && _board[1][0] == checkP) || (_board[2][1] == checkP && _board[2][2] == checkP)))
		{
			_board[2][0] = 'O';
			return;
		}
		checkP = 'X';
	}
	_state = getGameState();
	if (_state == InProgress)
	{
		bool b = true;
		do
		{
			int x = rand() % 3;
			int y = rand() % 3;
			if (_board[x][y] == '-')
			{
				_board[x][y] = 'O';
				b = false;
			}
		} while (b);
	}
}
