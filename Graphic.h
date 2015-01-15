#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Controleur.h"
using namespace std;


/***************************************
	Contient la totalité des méthodes
	de dessin pour l'application
****************************************/

class Graphic : public GraphicEngine
{

private:

	Controleur *ctrl;

	void background();
	void menu();
	void gameOver();

public:

	Graphic(Controleur *ctrl_);

	virtual void Draw();
	virtual void reshape(int ww_, int wh_);

};
