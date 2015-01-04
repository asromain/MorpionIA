#pragma once
#include <iostream>
#include "Engine.h"
#include "Grid.h"
#include "Pawn.h"
using namespace std;

/***************************************
	Permet de gérer le contrôle
	de notre application
****************************************/

class Control : public ControlEngine
{

private:

	Grid * gr;
	int *ww, *wh;            // windowsWidth et windowsHeight
	vector<Pawn *> *pawns;   // notre liste de pions

public:

	Control(Grid * gr_, int * ww_, int * wh_, vector<Pawn *> *pawns_);
	virtual void MouseCallback(int button, int state, int x, int y);

};
