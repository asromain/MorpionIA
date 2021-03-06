#pragma once
#include <iostream>
#include "Engine.h"
#include "Controleur.h"
using namespace std;

/***************************************
	Permet de g�rer le contr�le
	de notre application
****************************************/

class Control : public ControlEngine
{

private:

	Controleur *ctrl;

public:

	Control(Controleur *ctrl_);

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void KeyboardCallback(unsigned char key, int x, int y);
	virtual void specialCallback(int key, int x, int y);

};
