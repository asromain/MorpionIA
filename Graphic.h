#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Controlleur.h"
using namespace std;


/***************************************
	Contient la totalité des méthodes
	de dessin pour l'application
****************************************/

class Graphic : public GraphicEngine
{

private:

	Controlleur *ctrl;

	void background();
	void menu();
	void gameOver();

public:

	Graphic(Controlleur *ctrl_);

	virtual void Draw();
	virtual void reshape(int ww_, int wh_);

};
