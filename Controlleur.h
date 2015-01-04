#pragma once
#include "Grid.h"
#include "Pawn.h"
using namespace std;

/***************************************
Permet de gérer toutes les
animations dans notre application
****************************************/

class Controlleur
{

private:

	Grid * gr;
	int *ww, *wh;   // windowsWidth et windowsHeight
	vector<Pawn *> pawns;

public:

	Controlleur(Grid * gr_, int ww_, int wh_, vector<Pawn *> pawns_) :
		gr(gr_), pawns(pawns_) 
	{
		*ww = ww_;
		*wh = wh_;
	}

	Grid* getGr();
	int* getWw();
	int* getWh();
	vector<Pawn *>* getPawns();

	~Controlleur();
};
