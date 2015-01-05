#pragma once
#include "GraphicPrimitives.h"
using namespace std;


/***************************************
	Classe qui permet de créer une
	Case, sert à la classe Damier
****************************************/

class Case
{

private:

	float posX, posY;
	float width, height;
	float r, g, b;
	int type;            // type 0 = no type (case innoccupée) || type 1 = J1 || type 2 = J2

public:

	Case(float posX_, float posY_, float width_, float height_);

	void draw();
	float getPosX();
	float getPosY();
	float getWidth();
	float getHeight();
	char getType();
	void setType(int type_);

};