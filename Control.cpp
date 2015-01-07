#include "Control.h"
using namespace std;

Control::Control(Controlleur *ctrl_) : ctrl(ctrl_) 
{
	cout << "Creating control" << endl;
}

void Control::specialCallback(int key, int x, int y)
{
	//debug
	//std::cout << "status = " << ctrl->getStatus() << ", curseur = " << ctrl->getCurseur() << ", key = " << key << std::endl;
	switch (ctrl->getStatus())
	{
	case 0:
		if (key == '\r')
		{
			ctrl->reset();
			ctrl->setStatus(1);
		}
		break;
	case 1:
		break;
	default:
		ctrl->setStatus(0);
		break;
	}
}
void Control::KeyboardCallback(unsigned char key, int x, int y)
{
	//debug
	//std::cout << "status = " << ctrl->getStatus() << ", curseur = " << ctrl->getCurseur() << ", key = " << key << ", int = " << (int)key << std::endl;
	switch (ctrl->getStatus())
	{
	case 0:
		if (key == '\r')
		{
			ctrl->reset();
			ctrl->setStatus(1);
		}
		break;
	case 1:
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
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int line;
		int col;
		float fx = ctrl->pixelToRelativeX(x);
		float fy = ctrl->pixelToRelativeY(y);
		std::cout << "click  ! " << endl << "x = " << x << ", y = " << y << ", fx = " << fx << ", fy = " << fy << endl;
		switch (ctrl->getStatus())
		{
		case 0:
			if (-0.64 < fx && fx < -0.41 && 0.32 < fy && fy < 0.41) ctrl->setCurseurJ1(0);
			if (-0.64 < fx && fx < -0.41 && 0.18 < fy && fy < 0.27) ctrl->setCurseurJ1(1);
			if (-0.64 < fx && fx < -0.41 && 0.02 < fy && fy < 0.11) ctrl->setCurseurJ1(2);

			if (-0.02 < fx && fx < 0.05 && 0.32 < fy && fy < 0.41) ctrl->setCurseurT(0);
			if (-0.02 < fx && fx < 0.05 && 0.18 < fy && fy < 0.27) ctrl->setCurseurT(1);
			if (-0.02 < fx && fx < 0.05 && 0.02 < fy && fy < 0.11) ctrl->setCurseurT(2);

			if (0.52 < fx && fx < 0.75 && 0.32 < fy && fy < 0.41) ctrl->setCurseurJ2(0);
			if (0.52 < fx && fx < 0.75 && 0.18 < fy && fy < 0.27) ctrl->setCurseurJ2(1);
			if (0.52 < fx && fx < 0.75 && 0.02 < fy && fy < 0.11) ctrl->setCurseurJ2(2);

			if (-0.06 < fx && fx < 0.09 && -0.32 < fy && fy < -0.25)
			{
				ctrl->reset();
				ctrl->setStatus(1);
			}
			break;
		case 1:
			if ((!ctrl->getJ1ordi() == !ctrl->getTurnJ2()) || (!ctrl->getJ2ordi() == ctrl->getTurnJ2()))
			{
				cout << endl << endl << "click sur la grille" << endl;
				col = (x / (ctrl->getWw() / ctrl->getDim()));
				line = (y / (ctrl->getWh() / ctrl->getDim()));
				cout << "col : " << col << ", line : " << line << endl;
				ctrl->print();
				Case * c = ctrl->getGr()->getCase(line, col);
				if (c->getType() == 0)
				{
					ctrl->getGr()->action(col, line, ctrl->getTurnJ2() + 1);
					ctrl->isGameOver();
					ctrl->changeTurn();
					ctrl->print();
				}
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
}

