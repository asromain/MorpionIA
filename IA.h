#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/***************************************
Classe qui controle l'IA
****************************************/

class IA
{

private:

	int dim;

public:

	IA(int dim_);

	virtual int* play(int** matrix, int dim, int *j);
};