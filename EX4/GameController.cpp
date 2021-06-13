#include "GameController.h"
using namespace std;
void on(unique_ptr<ViewBoardGame> &view, unique_ptr<BoardGame> &model)
{
	int status;
	int TryAgain = 0;
	do
	{
		do
		{
			if (TryAgain == 0)
				status = view->drawBoard(model->getBoard(), model->getGameState());
			else
				TryAgain--;
			if (status == 0)
			{
				try
				{
					Move moveP = view->chooseMove();
					model->console(moveP);
				}
				catch (string &e)
				{
					TryAgain++;
					view->printErrorMessage(e);
				}
			}
		} while (status == 0);
		model->Rest();
	} while (status == 1);
}
int GameController::play()
{
	view = unique_ptr<ViewConsoleBoardGame>(new ViewConsoleBoardGame);
	int status;
	while (true)
	{
		int num = view->draw(1);
		switch (num)
		{
		case 1:
			switch (view->draw(2))
			{
			case 1:
				model = unique_ptr<TicTacToeRand>(new TicTacToeRand);
				on(view, model);
				break;
			case 2:
				model = unique_ptr<TicTacToeEdu>(new TicTacToeEdu);
				on(view, model);
				break;
			};
			break;
		case 2:
			return 0;
		default:
			view->draw(5);
			break;
		}
	}
	return 0;
}