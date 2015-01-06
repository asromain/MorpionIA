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

	Minmax();

	virtual int* play(int** matrix, int dim, int *j);
	int calculMin(int** matrix, int dim, int prof, int *j_);
	int calculMax(int** matrix, int dim, int prof, int *j_);
	int eval(int** matrix, int dim, int *j_);
};