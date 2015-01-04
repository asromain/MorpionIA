#pragma once
#include "Case.h"
#include <cassert>
#define DIM 3

/***
	Classe qui permet de cr�er le Damier, utilise la classe Case.
*/

class Grid
{

private:

	Case * board[DIM][DIM];         // le tableau de jeu qui comporte les cases
	float caseWidth, caseHeight;    // largeur et hauteur des cases

public:

	Grid();
	~Grid();
	void draw();

	Case * getCase(float coordX_, float coordY_, int ww_, int wh_);     // renvoie la case cliqu�e par rapport aux coordonn�es coordX et coordY
	Case * getCase(int line, int col);                                  // renvoie la case du tableau de jeu par rapport � l'indice ligne et colonne
	int getLine(float coordX_, float coordY_, int ww_, int wh_);
	int getCol(float coordX_, float coordY_, int ww_, int wh_);

};