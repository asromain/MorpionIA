#include "Controlleur.h"
using namespace std;

Controlleur::Controlleur()
{
	cout << "Creating controller" << endl;
	ww = WWIDTH;
	wh = WHEIGHT;
}

Grid* Controlleur::getGr()
{
	return gr;
}
int Controlleur::getWw()
{
	return ww;
}
int Controlleur::getWh()
{
	return wh;
}
void Controlleur::setWw(int n)
{
	ww = n;
}
void Controlleur::setWh(int n)
{
	wh = n;
}
int Controlleur::getStatus()
{
	return status;
}
bool Controlleur::getJ1ordi()
{
	return j1ordi;
}
bool Controlleur::getTurnJ2()
{
	return turn;
}
void Controlleur::setStatus(int n)
{
	status = n;
}
void Controlleur::changeTurn()
{
	turn = !turn;
}
void Controlleur::changeJ1ordi()
{
	j1ordi = !j1ordi;
}
bool Controlleur::getCurseur()
{
	return curseur;
}
void Controlleur::changeCurseur()
{
	curseur = !curseur;
}
int Controlleur::getGagnant()
{
	return gagnant;
}
void Controlleur::setGagnant(int n)
{
	gagnant = n;
}
void Controlleur::iaTurn(int j)
{
	int res[2];
	ia->play(gr->getMatrix(), DIM, res, j);
	gr->action(res[0], res[1], j);
}
void Controlleur::isGameOver()
{
	//ligne (à généraliser)
	for (int i = 0; i < DIM; i++) {
		int t = gr->getCase(i, 0)->getType();
		int lg = 0;
		for (int j = 0; j < DIM; j++) {
			if (t == gr->getCase(i, j)->getType()) {
				lg++;
			}
			else
			{
				t = gr->getCase(i, j)->getType();
				lg = 1;
			}
			if (lg == LONG_TO_WIN && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				changeTurn();
			}
		}
	}
	//colonne (à généraliser)
	for (int j = 0; j < DIM; j++) {
		int t = gr->getCase(0, j)->getType();
		int lg = 0;
		for (int i = 0; i < DIM; i++) {
			if (t == gr->getCase(i, j)->getType()) {
				lg++;
			}
			else
			{
				t = gr->getCase(i, j)->getType();
				lg = 1;
			}
			if (lg == LONG_TO_WIN && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				changeTurn();
			}
		}
	}
	//diagonale (à généraliser)
}
void Controlleur::print() 
{
	cout << "status : " << status << 
		", gagnant : " << gagnant <<
		", j1ordi : " << j1ordi << 
		", turn : " << turn << 
		", curseur : " << curseur << endl;
	gr->print();
}

void Controlleur::reset()
{
	delete gr;
	gr = new Grid();
	turn = 0;
}

int Controlleur::relativeToPixelX(float n)
{
	return ((n + 1) * ww) / 2;
}
float Controlleur::pixelToRelativeX(int n)
{
	float w = ww;
	return (n - (w / 2)) / (w / 2);
}
int Controlleur::relativeToPixelY(float n)
{
	return ((2 - (n + 1)) * wh) / 2;
}
float Controlleur::pixelToRelativeY(int n)
{
	float h = wh;
	return (n - (h / 2)) / -(h / 2);
}

// Destructeur
Controlleur::~Controlleur()
{
	delete ia;
	delete gr;
}