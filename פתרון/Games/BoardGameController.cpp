#include "BoardGameController.h"
#include "XO_Game.h"
#include "GetTheRabbit_Game.h"
#include <iostream>

using namespace std;

void BoardGameController::play()
{
    cout << "Hello, Please choose a game: \n 1 - XO\n 2 - Get the rabbit" << endl;
    int option = 0;
    cin >> option;
    switch (option)
    {
    case (1):
        XOGame();
        break;
    case (2):
        GetTheRabbitGame();
        break;
    default:
        cout << "Invalid option" << endl;
    }
}

void BoardGameController::move(Board *game)
{
    int turn = game->getPlayer();
    while (!game->gameOver())
    {
        game->showBoard();
        cout << (turn == 1 ? "Your turn:" : "Computer turn:") << endl;
        if (!game->play(turn))
        {
            cout << "Invalid Move" << endl;
            continue;
        }

        if (game->checkWin(turn))
        {
            cout << (turn == 1 ? "You win!" : "Computer Wins!") << endl;
            game->showBoard();
            return;
        }
        turn *= (-1);
    }
}

void BoardGameController::XOGame()
{
    cout << "Please choose you symbol: X or O" << endl;
    char symbol;
    cin >> symbol;
    if (symbol != 'X' && symbol != 'O')
    {
        cout << "Invalid symbol" << endl;
        return;
    }

    int playerSymbol = symbol == 'X' ? 1 : -1;
    int computerSymbol = playerSymbol * (-1);
    XO_Game *game = new XO_Game(playerSymbol, computerSymbol);
    move(game);
}

void BoardGameController::GetTheRabbitGame()
{
    cout << "Please choose the max number of steps:" << endl;
    int steps;
    cin >> steps;
    if (steps < 0)
    {
        cout << "Invalid number" << endl;
        return;
    }
    cout << "Please choose the first location of the child:" << endl;
    int x_player = 0, y_player = 0;
    cin >> x_player >> y_player;
    if (x_player < 0 || x_player >= 9 || y_player < 0 || y_player >= 9)
    {
        cout << "Invalid location" << endl;
        return;
    }
    cout << "Please choose the first location of the rabbit:" << endl;
    int x_comp = 0, y_comp = 0;
    cin >> x_comp >> y_comp;
    if (x_comp < 0 || x_comp >= 9 || y_comp < 0 || y_comp >= 9)
    {
        cout << "Invalid location" << endl;
        return;
    }
    GetTheRabbit_Game *game = new GetTheRabbit_Game(steps, x_player, y_player, x_comp, y_comp);
    move(game);
}