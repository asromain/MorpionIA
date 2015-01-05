#include "Control.h"
using namespace std;

Control::Control(Controlleur *ctrl_) : ctrl(ctrl_) 
{
	cout << "Creating control" << endl;
}

void Control::specialCallback(int key, int x, int y)
{
	//debug
	std::cout << "status = " << ctrl->getStatus() << ", curseur = " << ctrl->getCurseur() << ", key = " << key << std::endl;
	switch (ctrl->getStatus())
	{
	case 0:
		if (key == 101 || key == 103)
		{
			ctrl->changeCurseur();
			ctrl->changeJ1ordi();
		}
		if (key == '\r')
		{
			ctrl->reset();
			ctrl->setStatus(1);
		}
		break;
	default:
		ctrl->setStatus(0);
		break;
	}
}
void Control::KeyboardCallback(unsigned char key, int x, int y)
{
	//debug
	std::cout << "status = " << ctrl->getStatus() << ", curseur = " << ctrl->getCurseur() << ", key = " << key << ", int = " << (int)key << std::endl;
	switch (ctrl->getStatus())
	{
	case 0:
		if (key == '\r')
		{
			ctrl->reset();
			ctrl->setStatus(1);
		}
		break;
	default:
		ctrl->setStatus(0);
		break;
	}
}

/***
    Coordonnée x et y par rapport au haut gauche de la fenêtre
*/
void Control::MouseCallback(int button, int state, int x, int y)
{
	float fx = ctrl->pixelToRelativeX(x);
	float fy = ctrl->pixelToRelativeY(y);
	std::cout << "x = " << x << ", y = " << y << ", fx = " << fx << ", fy = " << fy << endl;
	switch (ctrl->getStatus())
	{
	case 0:
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (-0.17 < fx && fx < 0.1 && -0.02 < fy && fy < 0.07)
			{
				if (!ctrl->getJ1ordi()) ctrl->changeJ1ordi();
				ctrl->reset();
				ctrl->setStatus(1);
			}
			if (-0.17 < fx && fx < 0.1 && -0.52 < fy && fy < -0.43)
			{
				if (ctrl->getJ1ordi()) ctrl->changeJ1ordi();
				ctrl->reset();
				ctrl->setStatus(1);
			}
		}
		break;
	case 1:
		if (ctrl->getJ1ordi() == ctrl->getTurnJ2())
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				Case * c = ctrl->getGr()->getCase(fx, fy);
				if (c->getType() == 0)
				{
					ctrl->print();
					float posX = c->getPosX();
					float posY = c->getPosY();
					float width = c->getWidth();
					float height = c->getHeight();
					ctrl->getGr()->action(fx, fy, ctrl->getTurnJ2() + 1);
					ctrl->isGameOver();
					ctrl->changeTurn();
				}
			}
		}
		// pour debug
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			int line = ctrl->getGr()->getLine(x, y, ctrl->getWw(), ctrl->getWh());
			int col = ctrl->getGr()->getCol(x, y, ctrl->getWw(), ctrl->getWh());

			std::cout << "x:" << x << "; y:" << y << std::endl;
			std::cout << "line:" << line << "; col:" << col << std::endl;
		}
		break;
	case 2:
		ctrl->setStatus(0);
		break;
	default:
		ctrl->setStatus(0);
		break;
	}
}

