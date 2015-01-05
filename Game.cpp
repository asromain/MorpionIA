#include "Game.h"
using namespace std;

Game::Game(Controlleur *ctrl_) : ctrl(ctrl_) 
{
	cout << "Creating Game" << endl;
}
/***
	Fonction appelée par l'application
	en continue
*/
void Game::idle()
{
	switch (ctrl->getStatus())
	{
	case 1:
		if (ctrl->getJ1ordi() != ctrl->getTurnJ2())
		{
			ctrl->print();
			ctrl->iaTurn(ctrl->getTurnJ2() + 1);
			ctrl->isGameOver();
			ctrl->changeTurn();
		}
		break;
	default:
		break;
	}
}