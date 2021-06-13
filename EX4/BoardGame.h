#pragma once
#include "Game.h";

class BoardGame : public Game
{
public:
	BoardGame(int rows, int cols)
	{
		_rows = rows;
		_cols = cols;
	}
	vector<vector<char> > getBoard() const { return _board; }

protected:
	void printBoard(int size);
	int _rows, _cols;
	vector<vector<char> > _board;
	GameState _state;
};