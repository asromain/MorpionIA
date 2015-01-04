#include "Game.h"


Game::Game(Grid * gr_, int * ww_, int * wh_) :
	gr(gr_),
	ww(ww_),
	wh(wh_)
{}


/***
	Fonction appelée par l'application
	en continue
*/
void Game::idle()
{
	//ligne (à généraliser)
	for (int i = 0; i < 3; i++) {
		if (gr->getCase(i, 0)->getType() != 'n')
		{
			if ((gr->getCase(i, 0)->getType() == gr->getCase(i, 1)->getType() &&
				gr->getCase(i, 1)->getType() == gr->getCase(i, 2)->getType()))
			{
				std::cout << "GAGNANT par ligne" << std::endl;
			}
		}
	}
	//colonne (à généraliser)
	for (int j = 0; j < 3; j++) {
		if (gr->getCase(0, j)->getType() != 'n')
		{
			if ((gr->getCase(0, j)->getType() == gr->getCase(1, j)->getType() &&
				gr->getCase(1, j)->getType() == gr->getCase(2, j)->getType()))
			{
				std::cout << "GAGNANT par col" << std::endl;
			}
		}
	}
	//diagonale (à généraliser)
	
}