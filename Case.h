#pragma once
#include "GraphicPrimitives.h"


/***************************************
	Classe qui permet de cr�er une
	Case, sert � la classe Damier
****************************************/

class Case
{

private:

	float posX, posY;
	float width, height;
	float r, g, b;
	char type;            // type n = no type (case innoccup�e) || type h = human || type c = computer (ia) 

public:

	Case(float posX_, float posY_, float width_, float height_);

	void draw();
	float getPosX();
	float getPosY();
	float getWidth();
	float getHeight();
	char getType();
	void setType(char type_);

};