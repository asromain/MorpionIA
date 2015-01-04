#include <iostream>
#include "Engine.h"
#include "Graphic.h"
#include "Game.h"
#include "Control.h"
#include "Pawn.h"
#include "Controlleur.h"
using namespace std;

#define WWIDTH 800
#define WHEIGHT 600


int main(int argc, char * argv[])
{
    Engine e(argc,argv);
    
	Grid * gr = new Grid();
	vector<Pawn *> pawns;

	Controlleur* ctrl = new Controlleur(gr, WWIDTH, WHEIGHT, pawns);
    
	Graphic * ge = new Graphic(ctrl);
	Control * ce = new Control(ctrl);
	Game    * gme = new Game(ctrl);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
	
    e.start();

	delete gr;
	delete ctrl;

    return 0;
}
