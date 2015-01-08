#pragma once
#include <cstdlib>
#include <iostream>
#include <algorithm>    // algo max et min
#include "IA.h"
using namespace std;

/***************************************
Algorithme alpha beta
****************************************/

class Alphabeta : public IA
{

private:

	int dim;

public:

	Alphabeta(int dim_, int long_win_, int jr_);
	~Alphabeta();

	virtual int* play(int** matrix, int *j);

	void calcIA(int** matrix, int prof, int *j_);  // calcul prochaine coup
	int calculMin(int** matrix, int prof, int *j_, int alpha, int beta);
	int calculMax(int** matrix, int prof, int *j_, int alpha, int beta);
	int eval(int** matrix, int *j_);

};