#ifndef BOARD_H
#define BOARD_H
class Board
{
protected:
    int **matrix;
    int n;
    int m;
    int player;
    int computer;

public:
    Board(int n, int m, int player, int computer);
    void showBoard();
    virtual bool gameOver() = 0;
    virtual bool checkWin(int val) = 0;
    virtual bool play(int turn) = 0;
    bool updateBoard(int i, int j, int val);
    int getPlayer();
    int getComputer();
};

#endif