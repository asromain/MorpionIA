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
		menu(ctrl->getCurseur());
		break;
	case 1:
		ctrl->getGr()->draw();
		break;
	case 2:
		background();
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

void Graphic::menu(int c)
{
	/*
	Debug
	GraphicPrimitives::drawFillRect2D(-0.17, -0.02, 0.25, 0.09, 1.0, 1.0, 0.0);
	GraphicPrimitives::drawFillRect2D(-0.17, -0.52, 0.25, 0.09, 1.0, 1.0, 0.0);*/
	GraphicPrimitives::drawText2D("SELECT THE AI", -0.2, 0.5, 1.0, 1.0, 1.0);
	switch (c)
	{
	case 0:
		GraphicPrimitives::drawText2D("PLAYER 1", -0.15, 0.0, 1.0, 0.0, 0.0);
		GraphicPrimitives::drawText2D("PLAYER 2", -0.15, -0.5, 1.0, 1.0, 1.0);
		break;
	case 1:
		GraphicPrimitives::drawText2D("PLAYER 1", -0.15, 0.0, 1.0, 1.0, 1.0);
		GraphicPrimitives::drawText2D("PLAYER 2", -0.15, -0.5, 1.0, 0.0, 0.0);
		break;
	default:
		break;
	}
}
void Graphic::gameOver()
{
	std::stringstream out;
	if ((ctrl->getJ1ordi() && !ctrl->getGagnant()) || (!ctrl->getJ1ordi() && ctrl->getGagnant()))
	{
		GraphicPrimitives::drawText2D("L'ORDI A GAGNE", -0.15, 0.3, 1.0, 1.0, 1.0);
	}
	else
	{
		GraphicPrimitives::drawText2D("LE JOUEUR A GAGNE", -0.2, 0.3, 1.0, 1.0, 1.0);
	}
	GraphicPrimitives::drawText2D("Press any key to continue", -0.3, -0.4, 1.0, 1.0, 1.0);
}