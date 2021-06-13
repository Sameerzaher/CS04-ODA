#include "CatchTheBunny.h"

CatchTheBunny::CatchTheBunny(int move) :BoardGame(9, 9)
{
	_moveConst = move;
	_moveChange = 0;
	Rest();
}

void CatchTheBunny:: console(const Move& move)
{
	_state = getGameState();
	if (_state == PlayWins)
		_board[_xP][_yP] = 'W';
	performPlayerMove(Move(move.getX() + _xP, move.getY() + _yP));
	computerNextAIMove();
	
}
void CatchTheBunny::Rest()
{
	_moveChange = 0;
	_board.clear();
	vector<char> temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			temp.push_back('-');
		_board.push_back(temp);
		temp.clear();
	}
	bool b = true;
	do {
		_xP = rand() % 9; 
		_yP = rand() % 9; 
		if (_board[_xP][_yP] == '-') 
		{
			_board[_xP][_yP] = 'P';
			b = false;
		}
	} while (b);
	b = true;
	do {
		_xR = rand() % 9; 
		_yR = rand() % 9; 
		if (_board[_xR][_yR] == '-') 
		{
			_board[_xR][_yR] = 'R';
			b = false;
		}
	} while (b);
}
void CatchTheBunny::performPlayerMove(const Move& move)
{
	if (move.getX() < 0 || move.getX() >= 9 || move.getY() < 0 || move.getY() >= 9)
		throw string("Invalid Move\nTry again\n");
	_moveChange++;
	_board[_xP][_yP] = '-';
	_xP = move.getX(); 
	_yP = move.getY();
	_board[_xP][_yP] = 'P';
}

GameState CatchTheBunny::getGameState() const
{
	if (_xP == _xR && _yP == _yR)
		return PlayWins;
	if (_moveConst == _moveChange) 
	{
		return ComputerWins;
	}
	return InProgress;
}

void CatchTheBunny::move(int newx, int newy)
{
	if (newx < 0 || newx >= 9 || newy < 0 || newy >= 9)
		throw "";
	if (_board[_xR][_yR] != 'P')
		_board[_xR][_yR] = '-';
	_xR = newx;
	_yR = newy;
	_board[_xR][_yR] = 'R';
}

void CatchTheBunny::chooseComputerMove(int optionCount, int startNumber)
{
	
	int option = rand() % optionCount + startNumber; 
	switch (option)
	{
	case 1:	move(_xR - 1, _yR);	break;
	case 2:	move(_xR + 1, _yR);	break;
	case 3: move(_xR, _yR - 1);	break;
	case 4: move(_xR, _yR + 1);   break;
	}
}

void CatchTheBunnyRand::computerNextAIMove()
{
	bool b = true;
	while (b)
	{
		b = false;
		try 
		{
			chooseComputerMove();
		}
		catch (const char* e) 
		{
			b = true;
		}
	}
}

void CatchTheBunnyEdu::computerNextAIMove()
{
	bool b = true;
	while (b)
	{
		b = false;
		try 
		{
			if (_yP == _yR || _xP == _xR) 
			{
				if (_yP == _yR)
					chooseComputerMove(2, 3);
				else if (_xP == _xR)
					chooseComputerMove(2);
			}
			else 
			{
				chooseComputerMove();
			}
		}
		catch (string e)
		{
			b = true;
		}
	}
}