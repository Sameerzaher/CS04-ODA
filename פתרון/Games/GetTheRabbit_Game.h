#ifndef GetTheRabbit_Game_H
#define GetTheRabbit_Game_H

#include "Board.h"

class GetTheRabbit_Game : public Board {
    public:
        GetTheRabbit_Game(int steps, int x_player, int y_player, int x_comp, int y_comp);
        bool gameOver();
        bool checkWin(int val);
        bool play(int turn);
	private:
		int steps;
		int x_comp;
		int y_comp;
		int x_player;
		int y_player;		
		bool move(char direction, int turn);
};

#endif