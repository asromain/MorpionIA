#pragma once
#include "Grid.h"
#include "IA.h"
using namespace std;

#define WWIDTH 800
#define WHEIGHT 600
#define DIM 3
#define LONG_TO_WIN 3

/***************************************
Permet de gérer toutes les
animations dans notre application
****************************************/

class Controlleur
{

private:

	IA* ia = new IA();
	Grid * gr;
	int ww, wh;   // windowsWidth et windowsHeight
	int status = 0, gagnant = 0;
	bool j1ordi = true, turn = false, curseur = 0;

public:

	Controlleur();

	Grid* getGr();
	int getWw();
	int getWh();
	void setWw(int n);
	void setWh(int n);
	int getStatus();
	bool getJ1ordi(); 
	bool getTurnJ2();
	void setStatus(int n);
	void changeTurn();
	void changeJ1ordi();
	bool getCurseur();
	void changeCurseur();
	int getGagnant();
	void setGagnant(int n);
	void iaTurn(int j);
	void isGameOver();
	void print();

	void reset();

	int relativeToPixelX(float n);
	float pixelToRelativeX(int n);
	int relativeToPixelY(float n);
	float pixelToRelativeY(int n);

	~Controlleur();
};
