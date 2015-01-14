#include "Alphabeta.h"

Alphabeta::Alphabeta (int dim_, int long_win_, int profondeur_, int jr_) : Minmax(dim_, long_win_, profondeur_, jr_) {}

Alphabeta::~Alphabeta() {}

int* Alphabeta::play(int** matrix, int *j_)
{

	//cout << ">> PLAY: calculating minmax" << endl;
	int maxcourant = -1000000; // valeur outrageusement basse pour la comparer avec les autres
	int* res = new int[2]; // position choisit pour jouer
	//cout << "param :  lg_win : " << long_win << ", dim : " << dim << endl;
	//cout << "choice between : ";
	int prof = profondeur;
	//vector<int> ress;

	//on parcourt la matrice en quête d'un point jouable
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0) // on peux jouer ici
			{
				matrix[i][j] = *j_; // on joue
				int max = calculMin(matrix, profondeur, *j_, maxcourant); // on evalue le coup et on le compare avec ce qu'on a deja
				//ress.push_back(max);
				//if (max >= 10000 && (max / 10000) < prof) prof = (1 + (profondeur - (max / 10000)));
				//if (max <= -10000 && ((max / 10000) * -1) < prof) prof = ((1 + (profondeur - (max / 10000)))* -1);
				if (max > maxcourant) // si c'est mieux on le garde
				{
					maxcourant = max;
					res[0] = i;
					res[1] = j;
				}
				matrix[i][j] = 0; // on annule le coup
			}
		}
	}
	//cout << "res[0]=" << res[0] << ", res[1]=" << res[1] << endl;
	//cout << "on choisit : " << maxcourant << " parmis : ";
	/*for each (int n in ress)
	{
		cout << n << " ";
	}
	cout << endl;*/
	//profondeur = 3;
	return res; // on retourne la position qui a ete choisi comme la meilleure
}
/*
On evalue la position courante pour l'envoyer au calcMax sinon on cherche la plus petite valeur a garder
*/
int Alphabeta::calculMin(int** matrix, int prof, int j_, int alpha)
{
	//cout << endl << ">>calculMin, porf : " << prof << endl;
	int st, sc;
	eval(matrix, j_, &st, &sc); // on evalue le jeu
	//cout << "res[0]=" << st << ", res[1]=" << sc << endl;
	if (prof == 0)
	{
		//cout << "fin prof" << endl;
		return sc; // si on est dans la profondeur max on ira pas plus loin donc tant pis on retourne le jeu courant
	}
	if (st != 0)
	{
		//cout << "fin partie" << endl;
		return (sc * (prof + 1)); // la partie est fini on retourne le score (0 si egalite, 1000 si victoire)
	}

	int min = 1000000; // valeur trop grande pour comparer les resultat
	//vector<int> ress;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = autreJoueur(j_); // c'est a l'autre de jouer
				int tmp = calculMax(matrix, (prof - 1), autreJoueur(j_), min); // et on evalue
				if (tmp <= alpha)
				{
					matrix[i][j] = 0;
					return tmp;
				}
				//cout << "tmp : " << tmp << endl;
				//ress.push_back(tmp);
				if (tmp < min) min = tmp;

				matrix[i][j] = 0; // on annule le coup
			}
		}
	}/*
	 cout << "Prof " << prof << ", on choisit : " << min << " parmis : ";
	 for each (int n in ress)
	 {
	 cout << n << " ";
	 }
	 cout << endl;*/
	//cout << "min" << min << endl;
	return min;
}
int Alphabeta::calculMax(int** matrix, int prof, int j_, int alpha)
{
	//cout << endl << ">> calculMax, prof : " << prof << endl;
	int st, sc;
	eval(matrix, j_, &st, &sc);
	//cout << "res[0]=" << st << ", res[1]=" << sc << endl;
	if (prof == 0)
	{
		//cout << "fin prof" << endl;
		return sc; // si on est dans la profondeur max on ira pas plus loin donc tant pis on retourne le jeu courant
	}
	if (st != 0)
	{
		//cout << "fin partie" << endl;
		return (sc * (prof + 1)); // la partie est fini on retourne le score (0 si egalite, 1000 si victoire)
	}

	int max = -1000000;
	//vector<int> ress;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = autreJoueur(j_);
				int tmp = calculMin(matrix, (prof - 1), autreJoueur(j_), max);
				if (tmp >= alpha) 
				{
					matrix[i][j] = 0;
					return tmp;
				}
				//ress.push_back(max);
				//cout << "tmp : " << tmp << endl;
				if (tmp > max) max = tmp;
				matrix[i][j] = 0;
			}
		}
	}/*
	 cout << "Prof " << prof << ", on choisit : " << max << " parmis : ";
	 for each (int n in ress)
	 {
	 cout << n << " ";
	 }
	 cout << endl;*/
	//cout << "max : " << max << endl;
	return max;
}
