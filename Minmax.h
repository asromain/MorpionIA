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

	Minmax(int dim_, int long_win);

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int *j_);
	int calculMax(int** matrix, int prof, int *j_);
	int eval(int** matrix, int *j_);
	int calcScore(int** matrix, int* j_);
	int* jeuFini(int** matrix, int* j_);
	int comptePion(int** matrix);
};