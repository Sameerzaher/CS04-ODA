#ifndef XO_Game_H
#define XO_Game_H
#include "Board.h"

class XO_Game : public Board {
    public:
        XO_Game(int player, int computer);
        bool checkWin(int val);
        bool gameOver();
        bool play(int turn);
        
    private:
        bool checkRow(int row, int val);
        bool checkCol(int col, int val);
        bool checkDiagL(int val);
        bool checkDiagR(int val);
        void getEmptyPlace(int * x, int * y);
};

#endif