#pragma once
#include "TicTacToe.h"
#include "View.h"

class GameController
{
public:
	int play();

private:
	unique_ptr<ViewBoardGame> view;
	unique_ptr<BoardGame> model;
};
