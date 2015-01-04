#pragma once
#include "Engine.h"
#include "Grid.h"


/***************************************
	Permet de gérer toutes les
	animations dans notre application
****************************************/

class Game : public GameEngine
{

private:

	Grid * gr;
	int *ww, *wh;   // windowsWidth et windowsHeight

public:
		
	Game(Grid * gr_, int * ww_, int * wh_);
	virtual void idle();
	// testByLine
	// testByCol
	// testByDiag

};
