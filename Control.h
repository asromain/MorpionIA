#pragma once
#include <iostream>
#include "Engine.h"
#include "Controlleur.h"
using namespace std;

/***************************************
	Permet de gérer le contrôle
	de notre application
****************************************/

class Control : public ControlEngine
{

private:

	Controlleur *ctrl;

public:

	Control(Controlleur *ctrl_);

	virtual void MouseCallback(int button, int state, int x, int y);
	virtual void KeyboardCallback(unsigned char key, int x, int y);
	virtual void specialCallback(int key, int x, int y);

};
