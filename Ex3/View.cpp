#include "View.h"

int ViewConsoleBoardGame::draw(int num)
{
	switch (num)
	{
	case 1:
		system("cls");
		cout << "Choose one option:\n\t1.Tic Tac Toe\n\t3.Exit" << endl;
		break;
	case 2:
		system("cls");
		cout << "Choose option:\n\t1.low level\n\t2.hight level\n\t3.Exit" << endl;
		break;
	case 3:
		system("cls");
		cout << "Choose option : \n\t1.low level\n\t2.hight level\n\t3.Exit" << endl;
		break;
	case 4:
		cout << "Choose one option:\n\t1.Play Again\n\t2.Exite" << endl;
		break;
	case 5:
		cout << "Choose correct option" << endl;
		break;
	case 6:
		system("cls");
		cout << "how many moves you allow for this game? ";
		break;
	}
	int x;
	if (num != 6)
		cout << "Number option: ";
	cin >> x;
	return x;
}
int ViewBoardGame::drawBoard(vector<vector<char> > board, GameState state)
{
	_boardView = board;
	system("cls");
	int size = board.size();
	string s;
	if (size == 3)
		cout << "Welcome to Tic Tac Toe! \n User is 'X' & Computer is 'O'" << endl;
	switch (state)
	{
	case PlayWins:
		cout << "PlayWins" << endl;
		break;
	case ComputerWins:
		cout << "ComputerWins" << endl;
		break;
	case Tie:
		cout << "Tie" << endl;
		break;
	case InProgress:
		cout << "InProgress" << endl;
		break;
	}

	vector<char> temp;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (state == PlayWins && size == 9 && _boardView[i][j] != '-')
				_boardView[i][j] = 'W';
			cout << _boardView[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	if (state != InProgress)
		return draw(4);
	return 0;
}
Move ViewConsoleBoardGame::chooseMove()
{
	int coordinateX = 0, coordinateY = 0;
	if (_boardView.size() == 3)
	{
		cout << "Enter Coordinate X (1,2,3): ";
		cin >> coordinateX;
		cout << "Enter Coordinate Y (1,2,3): ";
		cin >> coordinateY;
		coordinateX--;
		coordinateY--;
	}
	else
	{
		int option;
		cout << "choose the desired and possible option:" << endl;
		cout << "1.Up\t2.Down\t3.Right\t4.Left:" << endl;
		cout << "Number option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			coordinateX--;
			break;
		case 2:
			coordinateX++;
			break;
		case 3:
			coordinateY++;
			break;
		case 4:
			coordinateY--;
			break;
		default:
			cout << "You must choose an impressive side" << endl;
			break;
		}
	}
	return Move(coordinateX, coordinateY);
}
void ViewConsoleBoardGame::printErrorMessage(string msg)
{
	cout << msg << endl;
}