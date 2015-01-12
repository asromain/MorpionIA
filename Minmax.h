#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include "IA.h"
using namespace std;

/***************************************
Classe qui controle l'IA
****************************************/

class Minmax :public IA
{

protected:

	int profondeur;

public:

	Minmax(int dim_, int long_win, int profondeur_, int jr_);

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int j_);
	int calculMax(int** matrix, int prof, int j_);
	virtual void eval(int** matrix, int j_, int* st, int* sc);
	virtual void evalJeu(int** matrix, int j_, int* st, int* sc);
	virtual int autreJoueur(int j_);
	virtual bool victoire(int** matrix);
	virtual bool nul(int** matrix);

	~Minmax();
};