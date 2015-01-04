#include "Graphic.h"


Graphic::Graphic(Grid * gr_, int * ww_, int * wh_, vector<Pawn *> *pawns_) :
	gr(gr_),
	ww(ww_),
	wh(wh_),
	pawns(pawns_)
{}


/***
	Fonction qui contient la totalité des primitives de dessins
*/
void Graphic::Draw()
{
	gr->draw();

	// dessine les pions
	for (int i = 0; i < pawns->size(); i++) {
		pawns->at(i)->draw();
	}
}


/***
	Fonction appelée à chaque redimensionnement de fenêtre
*/
void Graphic::reshape(int ww_, int wh_)
{
	*ww = ww_;
	*wh = wh_;
}