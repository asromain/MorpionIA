#include "Pawn.h"


Pawn::Pawn(float posX_, float posY_, float width_, float height_) :
	posX(posX_),
	posY(posY_),
	width(width_),
	height(height_),
	r(1.0f),
	g(0.737f),
	b(0.251f),
	type('h')              // joueur : human
{}

Pawn::Pawn(float posX_, float posY_, float width_, float height_, float r_, float g_, float b_) :
	posX(posX_),
	posY(posY_),
	width(width_),
	height(height_),
	r(r_),
	g(g_),
	b(b_),
	type('c')              // intelligence articielle : computer
{}

Pawn::~Pawn() {}

void Pawn::draw() 
{
	float x1 = posX + width / 4;
	float x2 = posX + (3 * width) / 8;
	float x3 = posX + (5 * width) / 8;
	float x4 = posX + (3 * width) / 4;
	float x5 = x3;
	float x6 = x2;

	float y1 = posY + height / 2;
	float y2 = posY + (3 * height) / 4;
	float y3 = y2;
	float y4 = y1;
	float y5 = posY + height / 4;
	float y6 = y5;

	std::vector<float> vectPosX = { x1, x2, x3, x4, x5, x6 };
	std::vector<float> vectPosY = { y1, y2, y3, y4, y5, y6 };

	GraphicPrimitives::drawFillPolygone2D(vectPosX, vectPosY, r, g, b);
}