#pragma once
#include "Move.h"
#include "GameState.h"
#include <vector>
#include <iostream>

using namespace std;
class ViewGame
{
public:
	virtual int draw(int num) = 0;
	virtual Move chooseMove() = 0;
	virtual void printErrorMessage(string msg) = 0;
};
class ViewBoardGame : public ViewGame
{
public:
	int drawBoard(vector<vector<char> > board, GameState state);

protected:
	vector<vector<char> > _boardView;
};
class ViewConsoleBoardGame : public ViewBoardGame
{
public:
	virtual int draw(int num);
	virtual Move chooseMove();
	virtual void printErrorMessage(string msg);
};
