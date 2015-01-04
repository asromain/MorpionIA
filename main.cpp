#include <iostream>
#include "Engine.h"
#include "Graphic.h"
#include "Game.h"
#include "Control.h"
#include "Pawn.h"
using namespace std;


int main(int argc, char * argv[])
{
    Engine e(argc,argv);
    
	Grid * gr = new Grid();
	int * ww = new int(800);               
	int * wh = new int(600);
	vector<Pawn *> pawns;
    
	Graphic * ge = new Graphic(gr, ww, wh, &pawns);
	Control * ce = new Control(gr, ww, wh, &pawns);
	Game    * gme = new Game(gr, ww, wh);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
	
    e.start();

	delete gr;
	delete ww;
	delete wh;

    return 0;
}
