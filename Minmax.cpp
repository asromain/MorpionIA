#include "Minmax.h"
using namespace std;

Minmax::Minmax(int dim_, int long_win_, int profondeur_, int jr_) : IA(dim_, long_win_, jr_), profondeur(profondeur_) {}

Minmax::~Minmax() {}

/*
Début du min max. Fonction apelle par le jeu et est en faite un calcMax
*/
int* Minmax::play(int** matrix, int *j_)
{
	cout << ">> PLAY: calculating minmax" << endl;
	int maxcourant = -1000000; // valeur outrageusement basse pour la comparer avec les autres
	int* res = new int[2]; // position choisit pour jouer
	//cout << "choice between : ";

	vector<int> ress;

	//on parcourt la matrice en quête d'un point jouable
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (matrix[i][j] == 0) // on peux jouer ici
			{
				matrix[i][j] = *j_; // on joue
				int max = calculMin(matrix, profondeur, *j_); // on evalue le coup et on le compare avec ce qu'on a deja
				ress.push_back(max);
				if ((max > maxcourant) || ((max == maxcourant) && (rand()%2))) // si c'est mieux on le garde
				{
					maxcourant = max;
					res[0] = i;
					res[1] = j;
				}
				matrix[i][j] = 0; // on annule le coup
			}
		}
	}
	cout << "res[0]=" << res[0] << ", res[1]=" << res[1] << endl;
	cout << "on choisit : " << maxcourant << " parmis : ";
	for each (int n in ress)
	{
		cout << n << " ";
	}
	cout << endl;
	return res; // on retourne la position qui a ete choisi comme la meilleure
}
/*
On evalue la position courante pour l'envoyer au calcMax sinon on cherche la plus petite valeur a garder
*/
int Minmax::calculMin(int** matrix, int prof, int j_) 
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
				int tmp = calculMax(matrix, (prof - 1), autreJoueur(j_)); // et on evalue
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
int Minmax::calculMax(int** matrix, int prof, int j_)
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
				int tmp = calculMin(matrix, (prof - 1), autreJoueur(j_));
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

void Minmax::eval(int** matrix, int j_, int* st, int* sc)
{
	int mult = (j_ == jr) ? 1 : -1;
	if (nul(matrix))
	{
		*st = 2;
		*sc = 0;
		return;
	}
	if (victoire(matrix))
	{
		*st = 1;
		*sc = (10000 * mult);
		return;
	}
	evalJeu(matrix, j_, st, sc);
	//cout << "eval donne : res[0]=" << *st << ", res[1]=" << *sc << endl;
	*sc *= mult;
}

/*
L'idee ici c'est qu'on va avancer sur la ligne et regarder si le joueur peu y faire une ligne gagnante ou si l'adversaire le peu.
si on peux pas faire de ligne la ligne n'est pas intéressante non plus, même si on y a des pions.
*/
void Minmax::evalJeu(int** matrix, int j_, int* st, int* sc)
{
	int longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0, longh1d = 0, longh2d = 0, longv1d = 0, longv2d = 0; // compte la longueur continue de jeu potentiel sur la ligne pour chaque joueur
	int score = 0, score1 = 0, score2 = 0; // pour le calcul des score
	int nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0, nbh1d = 0, nbh2d = 0, nbv1d = 0, nbv2d = 0; // nombre de pion du joueur dans le calcul des longueur de jeu poteniel
	int valv, valh; // valeur de point donné de la matrice
	int x, y;

	*st = 0;
	*sc = 0;

	// parcourt vertical et horizontal
	for (x = 0; x < dim; x++) // on parcour en même temps le lignes verticale et horizontale pour gagner un o(n2)
	{
		for (y = 0; y < dim; y++)
		{
			//cout << "boucle v & h" << endl;
			//verticale
			valv = matrix[x][y];
			//cout << "valv : " << valv << endl;
			if (valv == 1)
			{
				nbv1++;
				longv1++;
				if (longv2 >= long_win) score2 += (longv2 * 10) + (nbv2 * 10);
				nbv2 = 0;
				longv2 = 0;
			}
			if (valv == 2)
			{
				nbv2++;
				longv2++;
				if (longv1 >= long_win) score1 += (longv1 * 10) + (nbv1 * 10);
				nbv1 = 0;
				longv1 = 0;
			}
			if (valv == 0)
			{
				longv1++;
				longv2++;
			}

			//horizontale
			valh = matrix[y][x];
			if (valh == 1)
			{
				nbh1++;
				longh1++;
				if (longh2 >= long_win) score2 += (longh2 * 10) + (nbh2 * 10);
				nbh2 = 0;
				longh2 = 0;
			}
			if (valh == 2)
			{
				nbh2++;
				longh2++;
				if (longh1 >= long_win) score1 += (longh1 * 10) + (nbh1 * 10);
				nbh1 = 0;
				longh1 = 0;
			}
			if (valh == 0)
			{
				longh1++;
				longh2++;
			}
		}
		if (longh2 >= long_win) score2 += (longh2 * 10) + (nbh2 * 10);
		if (longh1 >= long_win) score1 += (longh1 * 10) + (nbh1 * 10);
		if (longv2 >= long_win) score2 += (longv2 * 10) + (nbv2 * 10);
		if (longv1 >= long_win) score1 += (longv1 * 10) + (nbv1 * 10);
		if (j_ == 1)
		{
			score += score1;
			score -= score2;
		}
		else
		{
			score -= score1;
			score += score2;
		}
		longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0;
		score1 = 0, score2 = 0;
		nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0;
	}

	longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0, longh1d = 0, longh2d = 0, longv1d = 0, longv2d = 0;
	score1 = 0, score2 = 0;
	nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0, nbh1d = 0, nbh2d = 0, nbv1d = 0, nbv2d = 0;

	//parcourt des diagonales
	for (x = 0; (x + long_win) <= dim; x++)
	{
		for (y = 0; (y + x) < dim; y++)
		{
			//cout << "boucle d" << endl;
			//descendante
			valh = matrix[x + y][y];
			if (valh == 1)
			{
				nbh1++;
				longh1++;
				if (longh2 >= long_win) score2 += (longh2 * 10) + (nbh2 * 10);
				nbh2 = 0;
				longh2 = 0;
			}
			if (valh == 2)
			{
				nbh2++;
				longh2++;
				if (longh1 >= long_win) score1 += (longh1 * 10) + (nbh1 * 10);
				nbh1 = 0;
				longh1 = 0;
			}
			if (valh == 0)
			{
				longh1++;
				longh2++;
			}
			if (x != 0)
			{
				valh = matrix[y][x + y];
				if (valh == 1)
				{
					nbh1d++;
					longh1d++;
					if (longh2d >= long_win) score2 += (longh2d * 10) + (nbh2d * 10);
					nbh2d = 0;
					longh2d = 0;
				}
				if (valh == 2)
				{
					nbh2d++;
					longh2d++;
					if (longh1d >= long_win) score1 += (longh1d * 10) + (nbh1d * 10);
					nbh1d = 0;
					longh1d = 0;
				}
				if (valh == 0)
				{
					longh1d++;
					longh2d++;
				}
			}
			//montante
			valv = matrix[x + y][(dim - 1) - y];
			if (valv == 1)
			{
				nbv1++;
				longv1++;
				if (longv2 >= long_win) score2 += (longv2 * 10) + (nbv2 * 10);
				nbv2 = 0;
				longv2 = 0;
			}
			if (valv == 2)
			{
				nbv2++;
				longv2++;
				if (longv1 >= long_win) score1 += (longv1 * 10) + (nbv1 * 10);
				nbv1 = 0;
				longv1 = 0;
			}
			if (valv == 0)
			{
				longv1++;
				longv2++;
			}
			if (x != 0)
			{
				valh = matrix[y][(dim - 1 - x) - y];
				if (valh == 1)
				{
					nbh1d++;
					longh1d++;
					if (longh2d >= long_win) score2 += (longh2d * 10) + (nbh2d * 10);
					nbh2d = 0;
					longh2d = 0;
				}
				if (valh == 2)
				{
					nbh2d++;
					longh2d++;
					if (longh1d >= long_win) score1 += (longh1d * 10) + (nbh1d * 10);
					nbh1d = 0;
					longh1d = 0;
				}
				if (valh == 0)
				{
					longh1d++;
					longh2d++;
				}
			}
		}
		if (longh2 >= long_win) score2 += (longh2 * 10) + (nbh2 * 10);
		if (longh1 >= long_win) score1 += (longh1 * 10) + (nbh1 * 10);
		if (longv2 >= long_win) score2 += (longv2 * 10) + (nbv2 * 10);
		if (longv1 >= long_win) score1 += (longv1 * 10) + (nbv1 * 10);
		if (longh2d >= long_win) score2 += (longh2d * 10) + (nbh2d * 10);
		if (longh1d >= long_win) score1 += (longh1d * 10) + (nbh1d * 10);
		if (longv2d >= long_win) score2 += (longv2d * 10) + (nbv2d * 10);
		if (longv1d >= long_win) score1 += (longv1d * 10) + (nbv1d * 10);

		if (j_ == 1)
		{
			score += score1;
			score -= score2;
		}
		else
		{
			score -= score1;
			score += score2;
		}
		longh1 = 0, longh2 = 0, longv1 = 0, longv2 = 0, longh1d = 0, longh2d = 0, longv1d = 0, longv2d = 0;
		score1 = 0, score2 = 0;
		nbh1 = 0, nbh2 = 0, nbv1 = 0, nbv2 = 0, nbh1d = 0, nbh2d = 0, nbv1d = 0, nbv2d = 0;
	}


	//cout << "fin" << endl;
	*st = 0;
	*sc = score;
	return;
}
int Minmax::autreJoueur(int j_)
{
	int res = (j_ == 1) ? 2 : 1;
	return res;
}
bool Minmax::victoire(int** matrix)
{
	int i, j;
	int t, tup, tdown;
	int lg, lgup, lgdown;
	// par ligne
	for (i = 0; i < dim; i++) {
		t = matrix[i][0];
		lg = 0;
		for (j = 0; j < dim; j++) {
			if (t == matrix[i][j]) {
				lg++;
			}
			else
			{
				t = matrix[i][j];
				lg = 1;
			}
			if (lg == long_win && t != 0)
			{
				return true;
			}
		}
	}

	//par colonnes 
	for (j = 0; j < dim; j++) {
		t = matrix[0][j];
		lg = 0;
		for (i = 0; i < dim; i++) {
			if (t == matrix[i][j]) {
				lg++;
			}
			else
			{
				t = matrix[i][j];
				lg = 1;
			}
			if (lg == long_win && t != 0)
			{
				return true;
			}
		}
	}
	// par diagonales
	for (j = 0; j < dim; j++)
	{
		//diagonale descendante
		lgup = 0;
		lgdown = 0;
		tup = matrix[0][j];
		tdown = matrix[dim - 1][j];
		for (i = 0; j + i < dim; i++) {
			if (tup == matrix[j + i][i]) {
				lgup++;
			}
			else
			{
				tup = matrix[j + i][i];
				lgup = 1;
			}
			if (tdown == matrix[(dim - 1) - j - i][dim - i - 1]) {
				lgdown++;
			}
			else
			{
				tdown = matrix[(dim - 1) - j - i][dim - i - 1];
				lgdown = 1;
			}
			if ((lgup == long_win && tup != 0) || (lgdown == long_win && tdown != 0))
			{
				return true;
			}
		}
		//diagonale montante
		lgup = 0;
		lgdown = 0;
		tup = matrix[0][j];
		tdown = matrix[dim - 1][j];
		for (i = 0; j - i >= 0; i++) {
			if (tup == matrix[j - i][i]) {
				lgup++;
			}
			else
			{
				tup = matrix[j - i][i];
				lgup = 1;
			}
			if (tdown == matrix[(dim - 1) - j + i][dim - i - 1]) {
				lgdown++;
			}
			else
			{
				tdown = matrix[(dim - 1) - j + i][dim - i - 1];
				lgdown = 1;
			}
			if ((lgup == long_win && tup != 0) || (lgdown == long_win && tdown != 0))
			{
				return true;
			}
		}
	}
	return false;
}
bool Minmax::nul(int** matrix)
{
	int x, y;
	bool egalite = true;

	for (x = 0; x < dim; x++) // egalite ?
	{
		for (y = 0; y < dim; y++)
		{
			if (matrix[x][y] == 0) egalite = false;
		}
	}

	return egalite;
}