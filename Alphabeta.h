#pragma once
#include <cstdlib>
#include <iostream>
#include <algorithm>    // algo max et min
#include "Minmax.h"
using namespace std;

/***************************************
Algorithme alpha beta
****************************************/

class Alphabeta : public Minmax
{

private:

public:

	Alphabeta(int dim_, int long_win, int profondeur_, int jr_);
	~Alphabeta();

	virtual int* play(int** matrix, int *j);
	int calculMin(int** matrix, int prof, int j_, int alpha);
	int calculMax(int** matrix, int prof, int j_, int alpha);

};