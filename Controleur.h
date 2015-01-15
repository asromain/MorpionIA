#pragma once
#include "Grid.h"
#include "IA.h"
#include "Minmax.h"
#include "Alphabeta.h"
using namespace std;

#define WWIDTH 800
#define WHEIGHT 600

/***************************************
Permet de gérer toutes les
animations dans notre application
****************************************/

class Controleur
{

private:

	int dim = 3, long_win = 3, prof = 8;
	IA* ia1;
	IA* ia2;
	Grid * gr;
	int ww, wh;   // windowsWidth et windowsHeight
	int status = 0, gagnant = 0;
	bool j1ordi = false, j2ordi = false, turn = false;
	int curseurJ1 = 0, curseurJ2 = 0, curseurT = 0;

public:

	Controleur();

	Grid* getGr();
	int getWw();
	int getWh();
	void setWw(int n);
	void setWh(int n);
	int getStatus();
	bool getJ1ordi(); 
	bool getJ2ordi();
	bool getTurnJ2();
	void setStatus(int n);
	void changeTurn();
	int getCurseurJ1();
	int getCurseurJ2();
	int getCurseurT();
	void setCurseurJ1(int n);
	void setCurseurJ2(int n);
	void setCurseurT(int n);
	int getGagnant();
	void setGagnant(int n);
	void ia1Turn(int j);
	void ia2Turn(int j);
	void isGameOver();
	void print();
	int getDim();

	void reset();

	int relativeToPixelX(float n);
	float pixelToRelativeX(int n);
	int relativeToPixelY(float n);
	float pixelToRelativeY(int n);

	~Controleur();
};
