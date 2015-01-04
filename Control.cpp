#include "Control.h"


Control::Control(Grid * gr_, int * ww_, int * wh_, vector<Pawn *> *pawns_) :
	gr(gr_),
	ww(ww_),
	wh(wh_),
	pawns(pawns_)
{}


/***
    Coordonnée x et y par rapport au haut gauche de la fenêtre
*/
void Control::MouseCallback(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Case * c = gr->getCase(x, y, *ww, *wh);
		float posX = c->getPosX();
		float posY = c->getPosY();
		float width = c->getWidth();
		float height = c->getHeight();

		if (c->getType() == 'n')                                     // 'n' = no pawn, case vide sans pion
		{
			pawns->push_back(new Pawn(posX, posY, width, height));   // on ajoute un pion de type 'h'
			c->setType('h');                                         // 'h' = human ...
		}
	}
	
	// pour debug
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
	{					
		int line = gr->getLine(x, y, *ww, *wh);
		int col = gr->getCol(x, y, *ww, *wh);

		std::cout << "x:" << x << "; y:" << y << std::endl;
		std::cout << "line:" << line << "; col:" << col << std::endl;
		std::cout << "nb pions : " << pawns->size() << std::endl;
	}
}

