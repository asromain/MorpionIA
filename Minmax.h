#pragma once
#include <cstdlib>
#include <iostream>
#include "IA.h"
using namespace std;

/***************************************
Algo minimax
****************************************/

class Minmax :public IA
{

private:

	int dim;

public:

	Minmax(int dim_);
	~Minmax();

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int *j_);
	int calculMax(int** matrix, int prof, int *j_);
	int eval(int** matrix, int *j_);
};