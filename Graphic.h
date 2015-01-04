#pragma once
#include <iostream>
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Grid.h"
#include "Pawn.h"
using namespace std;


/***************************************
	Contient la totalit� des m�thodes
	de dessin pour l'application
****************************************/

class Graphic : public GraphicEngine
{

private:

	Grid * gr;
	int *ww, *wh;            // windowsWidth, windowsHeight
	vector<Pawn *> *pawns;   // notre liste de pions

public:

	Graphic(Grid * gr_, int * ww_, int * wh_, vector<Pawn *> *pawns_);
	virtual void Draw();
	virtual void reshape(int ww_, int wh_);

};
