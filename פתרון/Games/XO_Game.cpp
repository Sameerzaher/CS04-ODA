#include "XO_Game.h"
#include <iostream>

using namespace std;
XO_Game::XO_Game(int player, int computer) : Board(3,3, player, computer) {}

bool XO_Game::checkRow(int row, int val) {
    for(int j = 0; j < m; j++) {
        if (matrix[row][j] != val) {
            return false;
        }
    }
    return true;
}

bool XO_Game::checkCol(int col, int val) {
    for(int i = 0; i < n; i++) {
        if (matrix[i][col] != val) {
            return false;
        }
    }
    return true;
}

bool XO_Game::checkDiagL(int val) {
    for(int i = 0; i < n; i++) {
        if (matrix[i][i] != val) {
            return false;
        }
    }
    return true;
}

bool XO_Game::checkDiagR(int val) {
    for(int i = 0; i < n; i++) {
        if (matrix[i][n - 1 - i] != val) {
            return false;
        }
    }
    return true;
}

bool XO_Game::checkWin(int val) {
    bool res = false;
    for (int i = 0; i < n; i++) {
        res |= checkRow(i, val);
    }
    for(int j = 0; j < m; j++) {
        res |= checkCol(j, val);
    }
    res |= checkDiagR(val);
    res |= checkDiagL(val);
    return res;
}

bool XO_Game::gameOver() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool XO_Game::play(int turn) {
    int x = 0, y = 0;
    if (turn == computer) {
        getEmptyPlace(&x, &y);
    }
    else {
        cout << "Please enter your move:" << endl;
        cin >> x >> y;
    }
    return updateBoard(x, y, turn);
}

void XO_Game::getEmptyPlace(int * x, int * y) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}