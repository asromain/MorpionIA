#pragma once
#include "GraphicPrimitives.h"
#include <vector>


/***
	Classe pour la gestion des pions
*/

class Pawn
{

private:

	float posX, posY;
	float width, height;
	float r, g, b;

public:

	Pawn(float posX_, float posY_, float width_, float height_);
	Pawn(float posX_, float posY_, float width_, float height_, float r_, float g_, float b_);
	~Pawn();
	void draw();

};