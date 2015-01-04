#include "Case.h"


Case::Case(float posX_, float posY_, float width_, float height_) :
	posX(posX_),
	posY(posY_),
	width(width_),
	height(height_),
	r(0.33f),
	g(0.33f),
	b(0.33f),
	type('n')          // pas de type == case vide
{}


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
void Case::setType(char type_) {
	type = type_;
}