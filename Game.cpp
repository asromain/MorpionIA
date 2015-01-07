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
		if (ctrl->getJ1ordi() && !ctrl->getTurnJ2())
		{
			cout << endl << endl << "l'ordi1 joue" << endl;
			ctrl->print();
			ctrl->ia1Turn(ctrl->getTurnJ2() + 1);
			ctrl->isGameOver();
			if (ctrl->getStatus() != 1) break;
			ctrl->changeTurn();
			ctrl->print();
		}
		if (ctrl->getJ2ordi() && ctrl->getTurnJ2())
		{
			cout << endl << endl << "l'ordi2 joue" << endl;
			ctrl->print();
			ctrl->ia2Turn(ctrl->getTurnJ2() + 1);
			ctrl->isGameOver();
			if (ctrl->getStatus() != 1) break;
			ctrl->changeTurn();
			ctrl->print();
		}
		break;
	default:
		break;
	}
}