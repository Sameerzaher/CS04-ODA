#pragma once
#include "BoardGame.h"

class CatchTheBunny : public BoardGame 
{
public:
	CatchTheBunny(int move);
	virtual void console(const Move& move);
	virtual void Rest();
	virtual void performPlayerMove(const Move& move);
	virtual GameState getGameState() const;
protected:
	void move(int newx, int newy);
	void chooseComputerMove(int optionCount = 4, int startNumber = 1);
protected:
	int _moveConst; 
	int _moveChange;
	int _xP, _yP, _xR, _yR;
};



class CatchTheBunnyRand : public CatchTheBunny 
{
public:
	CatchTheBunnyRand(int move) :CatchTheBunny(move) {}
	virtual void computerNextAIMove();

};

class CatchTheBunnyEdu : public CatchTheBunny
{
public:
	CatchTheBunnyEdu(int move) :CatchTheBunny(move) {}
	virtual void computerNextAIMove();
};
