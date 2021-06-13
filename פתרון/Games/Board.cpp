#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(int n, int m, int player, int computer) : n(n), m(m), player(player), computer(computer)
{
    matrix = new int*[n];
    for(int i = 0; i < n; i++)
        matrix[i] = new int[m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }
}

void Board::showBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                cout << "-";
            }
            else if (matrix[i][j] == 1) {
                cout << "X";
            }
            else {
                cout << "O";
            }
            if (j != m - 1) {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
bool Board::updateBoard(int i, int j, int val) {
    if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != 0) {
        return false;
    }
    matrix[i][j] = val;
    return true;
}

int Board::getPlayer() {
    return player;
}

int Board::getComputer() {
    return computer;
}