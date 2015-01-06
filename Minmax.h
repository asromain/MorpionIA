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

	virtual int* play(vector<vector<int>*> matrix, int dim, int *j);
	int calculMin(vector<vector<int>*>* matrix, int dim, int prof, int *j_);
	int calculMax(vector<vector<int>*>* matrix, int dim, int prof, int *j_);
	int eval(vector<vector<int>*>* matrix, int dim, int *j_);
};