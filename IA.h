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

protected:

	int dim, long_win, jr;

public:

	IA(int dim_, int long_win_, int jr_);

	virtual int* play(int** matrix, int *j);
};