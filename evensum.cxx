#include <iostream>
using namespace std;
int solve(int N, int v[])
{

	int max1, max2, contauguali = 0;
	int indice_max1;
	int num_pari = 0;

	max1 = v[0];

	for (int i = 0; i < N; i++)
		if (v[i] % 2 == 0)
			num_pari++; //trova quanti dei numeri sono pari

	for (int i = 0; i < N; i++)
		if (max1 <= v[i])
		{
			max1 = v[i];
			indice_max1 = i;
		} //cerca il max assoluto

	for (int i = 0; i < N; i++)
		if (max1 == v[i] && indice_max1 != i)
			contauguali++; // verifica che non vi siano due o più massimi coincidenti

	if (max1 % 2 == 0 && num_pari == 1)
	{
		if (indice_max1 + 1 < N)
		{
			max1 = v[indice_max1 + 1];
			indice_max1++;
		}

		else
		{
			max1 = v[indice_max1 - 1];
			indice_max1--;
		}

		for (int i = 0; i < N; i++)
			if (v[i] % 2 != 0 && max1 < v[i])
			{
				max1 = v[i];
				indice_max1 = i;
			}

		contauguali = 0;

		for (int i = 0; i < N; i++)
			if (max1 == v[i] && indice_max1 != i)
				contauguali++;
	}

	if (max1 % 2 != 0 && num_pari == N - 1)
	{
		if (indice_max1 + 1 < N)
		{
			max1 = v[indice_max1 + 1];
			indice_max1++;
		}

		else
		{
			max1 = v[indice_max1 - 1];
			indice_max1--;
		}

		for (int i = 0; i < N; i++)
			if (v[i] % 2 == 0 && max1 < v[i])
			{
				max1 = v[i];
				indice_max1 = i;
			}

		contauguali = 0;

		for (int i = 0; i < N; i++)
			if (max1 == v[i] && indice_max1 != i)
				contauguali++;
	}

	if (max1 % 2 == 0 && contauguali == 0)
	{
		for (int i = 0; i < N; i++)
			if (v[i] % 2 == 0 && v[i] < max1)
				max2 = v[i];

		for (int i = 0; i < N; i++)
			if (max2 < v[i] && v[i] % 2 == 0 && v[i] < max1)
				max2 = v[i];
	}

	if (max1 % 2 != 0 && contauguali == 0)
	{
		for (int i = 0; i < N; i++)
			if (v[i] % 2 != 0 && v[i] < max1)
				max2 = v[i];

		for (int i = 0; i < N; i++)
			if (max2 < v[i] && v[i] % 2 != 0 && v[i] < max1)
				max2 = v[i];
	}

	if (max1 % 2 == 0 && contauguali != 0)
		max2 = max1;

	if (max1 % 2 != 0 && contauguali != 0)
		max2 = max1;

	return max1 + max2;
}

int main()
{

	int N;
	std::cin >> N;
	int arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	std::cout << solve(N, arr); // Write to standard output

	return 0;
}
