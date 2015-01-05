#include "Case.h"
using namespace std;


Case::Case(float posX_, float posY_, float width_, float height_) :
	posX(posX_),
	posY(posY_),
	width(width_),
	height(height_),
	r(0.33f),
	g(0.33f),
	b(0.33f),
	type(0)          // pas de type == case vide
{
	cout << "creating case" << endl;
}


/***
	Fonction qui dessine une case en utilisant les primitives
	de dessin de polygone
*/
void Case::draw() {

	std::vector<float> vectPosX, vectPosY;

	vectPosX.push_back(posX);
	vectPosX.push_back(posX);
	vectPosX.push_back(posX + width);
	vectPosX.push_back(posX + width);

	vectPosY.push_back(posY);
	vectPosY.push_back(posY + height);
	vectPosY.push_back(posY + height);
	vectPosY.push_back(posY);

	GraphicPrimitives::drawFillPolygone2D(vectPosX, vectPosY, r, g, b);
	GraphicPrimitives::drawOutlinedPolygone2D(vectPosX, vectPosY, 0.8f, 0.8f, 0.8f);
	if (type == 1)
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

		GraphicPrimitives::drawFillPolygone2D(vectPosX, vectPosY, 1.0f, 0.737f, 0.251f);
	}
	if (type == 2)
	{
		GraphicPrimitives::drawLine2D(posX, posY, posX + width, posY + height, 0.737f, 0.251f, 1.0f);
		GraphicPrimitives::drawLine2D(posX + width, posY, posX, posY + height, 0.737f, 0.251f, 1.0f);
	}
}


/***
	GETTER
*/
float Case::getPosX() {
	return posX;
}
float Case::getPosY(){
	return posY;
}
float Case::getWidth(){
	return width;
}
float Case::getHeight(){
	return height;
}
char Case::getType() {
	return type;
}
void Case::setType(int type_) {
	type = type_;
}