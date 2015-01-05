#include "Game.h"
using namespace std;

Game::Game(Controlleur *ctrl_) : ctrl(ctrl_) 
{
	cout << "Creating Game" << endl;
}
/***
	Fonction appel�e par l'application
	en continue
*/
void Game::idle()
{
	switch (ctrl->getStatus())
	{
	case 1:
		if (ctrl->getJ1ordi() != ctrl->getTurnJ2())
		{
			cout << endl << endl << "l'ordi joue" << endl;
			ctrl->print();
			ctrl->iaTurn(ctrl->getTurnJ2() + 1);
			ctrl->isGameOver();
			ctrl->changeTurn();
			ctrl->print();
		}
		break;
	default:
		break;
	}
}