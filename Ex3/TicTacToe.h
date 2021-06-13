#pragma once
#include "BoardGame.h"

class TicTacToe : public BoardGame
{
public:
	TicTacToe();
	virtual void Rest();
	virtual void console(const Move& move);
	virtual void performPlayerMove(const Move& move);
	virtual GameState getGameState() const;
};

class TicTacToeRand : public TicTacToe
{
public:

	virtual void computerNextAIMove();
};

class TicTacToeEdu : public TicTacToe 
{ 
public:

	virtual void computerNextAIMove();

};
