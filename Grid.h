#pragma once
#include "Case.h"
#include <cassert>
#include <vector>
using namespace std;

/***
Classe qui permet de cr�er le Damier, utilise la classe Case.
*/

class Grid
{

private:

	int dim;           // dimension de la grille
	Case*** board;    // le tableau de jeu qui comporte les cases
	int** matrix;
	float caseWidth, caseHeight;   // largeur et hauteur des cases

public:

	Grid(int dim_);
	~Grid();
	void draw();

	Case * getCase(float fx, float fy);     // renvoie la case cliqu�e par rapport aux coordonn�es coordX et coordY
	Case * getCase(int line, int col);                                  // renvoie la case du tableau de jeu par rapport � l'indice ligne et colonne
	int getLine(float coordX_, float coordY_, int ww_, int wh_);
	int getCol(float coordX_, float coordY_, int ww_, int wh_);
	int** getMatrix();
	void action(int idCol, int idLine, int joueur);
	void actionIA(int x, int y, int joueur);
	void print();

};