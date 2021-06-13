#pragma once
#include "CatchTheBunny.h"
#include "TicTacToe.h" 
#include "View.h"
class BoardGameController
{
public:
	int play();
private:
	unique_ptr<ViewBoardGame> view; 
	unique_ptr<BoardGame> model;
};

