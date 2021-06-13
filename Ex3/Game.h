#pragma once
#include <vector>
#include <iostream>
#include "Move.h"
#include "GameState.h"
using namespace std;
class Game
{ 
public:
	virtual void console(const Move& move) = 0;
	virtual void Rest() = 0;
	virtual void computerNextAIMove() = 0;
	virtual void performPlayerMove(const Move& move) = 0;
	virtual GameState getGameState() const = 0;
};
