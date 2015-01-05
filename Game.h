#pragma once
#include "Engine.h"
#include "Controlleur.h"
using namespace std;


/***************************************
	Permet de gérer toutes les
	animations dans notre application
****************************************/

class Game : public GameEngine
{

private:

	Controlleur *ctrl;

public:
		
	Game(Controlleur *ctrl_);
	virtual void idle();
	// testByLine
	// testByCol
	// testByDiag

};
