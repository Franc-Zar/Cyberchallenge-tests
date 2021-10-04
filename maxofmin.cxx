#include <iostream>
#include <cstdlib>

using namespace std;

void solve(int N, int V[])
{

  int sol[N];
  int dim_subsq = 1;
  int maxofmin;
  int indice = 0;
  int min;

  while (dim_subsq <= N)
  {

    int minimi[N - dim_subsq + 1];

    for (int i = 0; i <= N - dim_subsq; i++)
    {
      min = V[i];
      for (int j = 0; j < dim_subsq; j++)
        if (V[i + j] < min)
          min = V[i + j];

      minimi[i] = min;
    }
  }
}

maxofmin = minimi[0];

for (int i = 1; i < N - dim_subsq + 1; i++)
  if (maxofmin < minimi[i])
    maxofmin = minimi[i];

sol[indice] = maxofmin;
indice++;
dim_subsq++;

for (int i = 0; i < N; i++)
{
  std::cout << sol[i];
  if (i < N - 1)
  {
    std::cout << " ";
  }
  else
  {
    std::cout << std::endl;
  }
}
}

int main()
{
  int N;
  cin >> N;
  int V[N];
  for (int i = 0; i < N; i++)
    V[i] = rand();
  solve(N, V);
  return 0;
}