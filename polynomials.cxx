#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void genera_polinomiale(int, int, int[]);
int numero_casuale(int);
void azzera_polinomiale(int, int, int[]);

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n, k;

	cout << "inserisci n e k" << endl;
	cin >> n >> k;

	int dim = n + 1;
	int coefficienti[dim];

	genera_polinomiale(k, dim, coefficienti);

	for (int z : coefficienti)
		cout << z << " ";

	azzera_polinomiale(k, dim, coefficienti);

	return 0;
}

void genera_polinomiale(int k, int n, int x[])
{

	int somma = 0;
	while (somma == 0)
	{
		for (int i = 0; i < n; i++)
		{
			x[i] = numero_casuale(k);
			somma += x[i] * pow(2, i);
		}
	}
}

int numero_casuale(int k)
{
	return rand() % ((2 * k) + 1) + (-k);
}

void azzera_polinomiale(int k, int n, int x[])
{
	int soluzioni = 0;
	int somma = 0;
	int appoggio;
	for (int i = 0; i < n; i++)
		somma += x[i] * pow(2, i);

	for (int i = 0; i < n; i++)
	{
		appoggio = -somma + x[i] * pow(2, i);

		if ((appoggio % (int)pow(2, i)) == 0 && (appoggio / pow(2, i)) <= k && (appoggio / pow(2, i)) >= -k)
			soluzioni++;
	}

	cout << endl
			 << soluzioni;
}