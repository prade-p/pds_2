#include <iostream>
// MAP
#include <map>
// VECTOR
#include <vector>
// STRING
#include <string>
// SORT
#include <algorithm>

using namespace std;

int main()
{
  int n_individuos;
  vector<int> quantidade_de_especies;
  while (true)
  {
    cin >> n_individuos;
    if (n_individuos == 0 || cin.peek() != '\n')
      break;
    map<string, int> combinacao_bases;
    for (int i = 0; i < n_individuos; i++)
    {
      string dna_mutante;
      cin >> dna_mutante;
      sort(dna_mutante.begin(), dna_mutante.end());
      combinacao_bases[dna_mutante]++;
    }
    quantidade_de_especies.push_back(combinacao_bases.size());
  }

  for (int j = 0; j < quantidade_de_especies.size(); j++)
  {
    cout << quantidade_de_especies[j] << endl;
  }

  return 0;
}