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
bool Controlleur::getJ2ordi()
{
	return j2ordi;
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
int Controlleur::getCurseurJ1()
{
	return curseurJ1;
}
int Controlleur::getCurseurJ2()
{
	return curseurJ2;
}
int Controlleur::getCurseurT()
{
	return curseurT;
}
void Controlleur::setCurseurJ1(int n)
{
	curseurJ1 = n;
}
void Controlleur::setCurseurJ2(int n)
{
	curseurJ2 = n;
}
void Controlleur::setCurseurT(int n)
{
	curseurT = n;
}
int Controlleur::getGagnant()
{
	return gagnant;
}
void Controlleur::setGagnant(int n)
{
	gagnant = n;
}
void Controlleur::ia1Turn(int j)
{
	int* res = ia1->play(gr->getMatrix(), &j);
	gr->actionIA(res[0], res[1], j);
	delete[] res;
}
void Controlleur::ia2Turn(int j)
{
	int* res = ia2->play(gr->getMatrix(), &j);
	gr->actionIA(res[0], res[1], j);
	delete[] res;
}
void Controlleur::isGameOver()
{
	bool egalite = true;
	int i, j;      // indices boucle
	int t, lg;  // dim-1, type, longueur
	int lgup, lgdown;
	int tup, tdown;

	// par ligne
	for (i = 0; i < dim; i++) {
		t = gr->getCase(i, 0)->getType();
		lg = 0;
		for (j = 0; j < dim; j++) {
			if (t == gr->getCase(i, j)->getType()) {
				lg++;
			}
			else
			{
				t = gr->getCase(i, j)->getType();
				lg = 1;
			}
			if (gr->getCase(i, j)->getType() == 0)
			{
				egalite = false;
			}
			if (lg == long_win && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				cout << endl << "===> gagnant par ligne" << endl << endl;
				return;
			}
		}
	}

	//par colonnes 
	for (j = 0; j < dim; j++) {
		t = gr->getCase(0, j)->getType();
		lg = 0;
		for (i = 0; i < dim; i++) {
			if (t == gr->getCase(i, j)->getType()) {
				lg++;
			}
			else
			{
				t = gr->getCase(i, j)->getType();
				lg = 1;
			}
			if (lg == long_win && t != 0)
			{
				setStatus(2);
				gagnant = turn + 1;
				cout << endl << "===> gagnant par colonne" << endl << endl;
				return;
			}
		}
	}

	// par diagonales
	for (j = 0; j < dim; j++) 
	{
		//diagonale descendante
		lgup = 0;
		lgdown = 0;
		tup = gr->getCase(0, j)->getType();
		tdown = gr->getCase(dim-1, j)->getType();
		for (int i = 0; j+i < dim; i++) {
			if (tup == gr->getCase(j+i, i)->getType()) {
				lgup++;
			}
			else
			{
				tup = gr->getCase(j+i, i)->getType();
				lgup = 1;
			}
			if (tdown == gr->getCase((dim - 1) - j - i, dim - i - 1)->getType()) {
				lgdown++;
			}
			else
			{
				tdown = gr->getCase((dim - 1) - j - i, dim - i - 1)->getType();
				lgdown = 1;
			}
			if ((lgup == long_win && tup != 0) || (lgdown == long_win && tdown != 0))
			{
				setStatus(2);
				gagnant = turn + 1;
				cout << endl << "===> gagnant par diagonale descendante" << endl << endl;
				return;
			}
		}
		//diagonale montante
		lgup = 0;
		lgdown = 0;
		tup = gr->getCase(0, j)->getType();
		tdown = gr->getCase(dim-1, j)->getType();
		for (int i = 0; j - i > 0; i++) {
			if (tup == gr->getCase(j - i, i)->getType()) {
				lgup++;
			}
			else
			{
				tup = gr->getCase(j - i, i)->getType();
				lgup = 1;
			}
			if (tdown == gr->getCase((dim - 1) - j + i, dim - i - 1)->getType()) {
				lgdown++;
			}
			else
			{
				tdown = gr->getCase((dim - 1) - j + i, dim - i - 1)->getType();
				lgdown = 1;
			}
			if ((lgup == long_win && tup !=0) || (lgdown == long_win && tdown != 0))
			{
				setStatus(2);
				gagnant = turn + 1;
				cout << endl << "===> gagnant par diagonale montante" << endl << endl;
				return;
			}
		}
	}
	if (egalite)
	{
		setStatus(2);
		gagnant = 0;
		return;
	}
}
void Controlleur::print()
{
	cout << "status : " << status <<
		", gagnant : " << gagnant <<
		", j1ordi : " << j1ordi <<
		", turn : " << turn << endl;
	gr->print();
}
int Controlleur::getDim()
{
	return dim;
}

void Controlleur::reset()
{
	delete gr;
	delete ia1;
	delete ia2;
	j1ordi = false;
	j2ordi = false;
	if (curseurT == 0) { dim = 3; long_win = 3; prof = 8; }
	if (curseurT == 1) { dim = 5; long_win = 4; prof = 4; }
	if (curseurT == 2) { dim = 10; long_win = 5; prof = 2; }
	gr = new Grid(dim);
	if (curseurJ1 != 0)
	{
		j1ordi = true;
		if (curseurJ1 == 1) ia1 = new IA(dim, long_win, 1);
		if (curseurJ1 == 2) ia1 = new Minmax(dim, long_win, prof, 1);
	}
	if (curseurJ2 != 0)
	{
		j2ordi = true;
		if (curseurJ2 == 1) ia2 = new IA(dim, long_win, 2);
		if (curseurJ2 == 2) ia2 = new Minmax(dim, long_win, prof, 2);
	}
	turn = 0;
	gagnant = 0;
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
	delete ia1;
	delete ia2;
	delete gr;
}