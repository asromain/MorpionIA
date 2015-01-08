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

private:

public:

	Minmax(int dim_, int long_win, int jr_);

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int j_);
	int calculMax(int** matrix, int prof, int j_);
	void eval(int** matrix, int j_, int* st, int* sc);
	void evalJeu(int** matrix, int j_, int* st, int* sc);
	int autreJoueur(int j_);

	~Minmax();
};