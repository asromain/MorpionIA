#pragma once
#include "Case.h"
#include <cassert>
#include <vector>
using namespace std;

#define DIM 3

/***
Classe qui permet de créer le Damier, utilise la classe Case.
*/

class Grid
{

private:

	Case * board[DIM][DIM];         // le tableau de jeu qui comporte les cases
	int** matrix;
	float caseWidth, caseHeight;    // largeur et hauteur des cases

public:

	Grid();
	~Grid();
	void draw();

	Case * getCase(float fx, float fy);     // renvoie la case cliquée par rapport aux coordonnées coordX et coordY
	Case * getCase(int line, int col);                                  // renvoie la case du tableau de jeu par rapport à l'indice ligne et colonne
	int getLine(float coordX_, float coordY_, int ww_, int wh_);
	int getCol(float coordX_, float coordY_, int ww_, int wh_);
	int** getMatrix();
	void action(int idCol, int idLine, int joueur);
	void actionIA(int x, int y, int joueur);
	void print();

};