#include "Controlleur.h"

Grid* Controlleur::getGr()
{
	return gr;
}
int* Controlleur::getWw()
{
	return ww;
}
int* Controlleur::getWh()
{
	return wh;
}
vector<Pawn *>* Controlleur::getPawns()
{
	return &pawns;
}

Controlleur::~Controlleur()
{
	delete ww;
	delete wh;
}