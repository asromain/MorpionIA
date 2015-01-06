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

	int dim;

public:

	Minmax(int dim_);

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int *j_);
	int calculMax(int** matrix, int prof, int *j_);
	int eval(int** matrix, int *j_);
};