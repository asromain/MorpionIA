#include "Graphic.h"


Graphic::Graphic(Grid * gr_, int * ww_, int * wh_, vector<Pawn *> *pawns_) :
	gr(gr_),
	ww(ww_),
	wh(wh_),
	pawns(pawns_)
{}


/***
	Fonction qui contient la totalit� des primitives de dessins
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
	Fonction appel�e � chaque redimensionnement de fen�tre
*/
void Graphic::reshape(int ww_, int wh_)
{
	*ww = ww_;
	*wh = wh_;
}