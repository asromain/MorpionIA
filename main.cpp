#include <iostream>
#include <ctime>
#include "Engine.h"
#include "Graphic.h"
#include "Game.h"
#include "Control.h"
#include "Controlleur.h"
using namespace std;


int main(int argc, char * argv[])
{
    Engine e(argc,argv);

	int dim = 3;
	Controlleur* ctrl = new Controlleur();
    
	Graphic * ge = new Graphic(ctrl);
	Control * ce = new Control(ctrl);
	Game    * gme = new Game(ctrl);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
	
	srand(time(NULL));

    e.start();

	delete ctrl;

    return 0;
}
