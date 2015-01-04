#pragma once
#include <iostream>
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

public:

	Graphic(Controlleur *ctrl_) : ctrl(ctrl_) {}
	virtual void Draw();
	virtual void reshape(int ww_, int wh_);

};
