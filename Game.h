#pragma once
#include "Engine.h"
#include "Controleur.h"
using namespace std;


/***************************************
	Permet de gérer toutes les
	animations dans notre application
****************************************/

class Game : public GameEngine
{

private:

	Controleur *ctrl;

public:
		
	Game(Controleur *ctrl_);
	virtual void idle();
	// testByLine
	// testByCol
	// testByDiag

};
