#include "Graphic.h"
using namespace std;

Graphic::Graphic(Controlleur *ctrl_) : ctrl(ctrl_) 
{
	cout << "Creating Graphic" << endl;
}

/***
	Fonction qui contient la totalité des primitives de dessins
*/
void Graphic::Draw()
{
	switch (ctrl->getStatus())
	{
	case 0:
		background();
		menu();
		break;
	case 1:
		ctrl->getGr()->draw();
		break;
	case 2:
		ctrl->getGr()->draw();
		gameOver();
		break;
	default:
		break;
	}
}


/***
	Fonction appelée à chaque redimensionnement de fenêtre
*/
void Graphic::reshape(int ww_, int wh_)
{
	ctrl->setWh(wh_);
	ctrl->setWw(ww_);
}

void Graphic::background()
{
	std::vector<float> xs;
	xs.push_back(-1.0);
	xs.push_back(1.0);
	xs.push_back(1.0);
	xs.push_back(-1.0);
	std::vector<float> ys;
	ys.push_back(1.0);
	ys.push_back(1.0);
	ys.push_back(-1.0);
	ys.push_back(-1.0);
	GraphicPrimitives::drawFillPolygone2D(xs, ys, 0.0, 0.0, 0.0);
}

void Graphic::menu()
{
	/*
	Debug
	GraphicPrimitives::drawFillRect2D(-0.64, 0.32, 0.23, 0.09, 1.0, 1.0, 0.0);
	GraphicPrimitives::drawFillRect2D(-0.02, 0.18, 0.07, 0.09, 1.0, 1.0, 0.0);
	GraphicPrimitives::drawFillRect2D(0.52, 0.02, 0.23, 0.09, 1.0, 1.0, 0.0);
	GraphicPrimitives::drawFillRect2D(-0.06, -0.32, 0.15, 0.09, 1.0, 1.0, 0.0);*/

	GraphicPrimitives::drawText2D("PLAYER 1", -0.63, 0.6, 1.0, 1.0, 1.0);
	GraphicPrimitives::drawText2D("PLAYER 2", 0.53, 0.6, 1.0, 1.0, 1.0);
	GraphicPrimitives::drawText2D("SIZE", -0.05, 0.6, 1.0, 1.0, 1.0);
	GraphicPrimitives::drawText2D("PLAY", -0.05, -0.3, 1.0, 1.0, 1.0);
	switch (ctrl->getCurseurJ1())
	{
	case 0:
		GraphicPrimitives::drawText2D("HUMAN", -0.63, 0.35, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("RANDOM", -0.63, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", -0.63, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", -0.63, -0.1, 1.0, 1.0, 1.0);
		break;
	case 1:
		GraphicPrimitives::drawText2D("HUMAN", -0.63, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", -0.63, 0.2, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("MINMAX", -0.63, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", -0.63, -0.1, 1.0, 1.0, 1.0);
		break;
	case 2:
		GraphicPrimitives::drawText2D("HUMAN", -0.63, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", -0.63, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", -0.63, 0.05, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("ALPHA", -0.63, -0.1, 1.0, 1.0, 1.0);
	case 3:
		GraphicPrimitives::drawText2D("HUMAN", -0.63, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", -0.63, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", -0.63, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", -0.63, -0.1, 1.0, 0.0, 0.0);
	default:
		break;
	}
	switch (ctrl->getCurseurJ2())
	{
	case 0:
		GraphicPrimitives::drawText2D("HUMAN", 0.53, 0.35, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("RANDOM", 0.53, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", 0.53, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", 0.53, -0.1, 1.0, 1.0, 1.0);
		break;
	case 1:
		GraphicPrimitives::drawText2D("HUMAN", 0.53, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", 0.53, 0.2, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("MINMAX", 0.53, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", 0.53, -0.1, 1.0, 1.0, 1.0);
		break;
	case 2:
		GraphicPrimitives::drawText2D("HUMAN", 0.53, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", 0.53, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", 0.53, 0.05, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("ALPHA", 0.53, -0.1, 1.0, 1.0, 1.0);
	case 3:
		GraphicPrimitives::drawText2D("HUMAN", 0.53, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("RANDOM", 0.53, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("MINMAX", 0.53, 0.05, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("ALPHA", 0.53, -0.1, 1.0, 0.0, 0.0);
	default:
		break;
	}
	switch (ctrl->getCurseurT())
	{
	case 0:
		GraphicPrimitives::drawText2D("3", -0.01, 0.35, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("5", -0.01, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("10", -0.01, 0.05, 1.0, 1.0, 1.0);
		break;
	case 1:
		GraphicPrimitives::drawText2D("3", -0.01, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("5", -0.01, 0.2, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("10", -0.01, 0.05, 1.0, 1.0, 1.0);
		break;
	case 2:
		GraphicPrimitives::drawText2D("3", -0.01, 0.35, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("5", -0.01, 0.2, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("10", -0.01, 0.05, 1.0, 0.0, 0.0);
	default:
		break;
	}
}
void Graphic::gameOver()
{
	switch (ctrl->getGagnant())
	{
	case 0:
		GraphicPrimitives::drawText2D("EGALITE", -0.1, 0.3, 1.0, 1.0, 1.0);
		break;
	case 1:
		GraphicPrimitives::drawText2D("LE JOUEUR 1", -0.2, 0.3, 1.0, 1.0, 1.0);
		break;
	case 2:
		GraphicPrimitives::drawText2D("LE JOUEUR 2", -0.2, 0.3, 1.0, 1.0, 1.0);
		break;
	default:
		break;
	}
	GraphicPrimitives::drawText2D("Press any key to continue", -0.3, -0.4, 1.0, 1.0, 1.0);
}