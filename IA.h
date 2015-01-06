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

public:

	IA();

	virtual int* play(int** matrix, int dim, int *j);
};