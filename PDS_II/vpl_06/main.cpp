#include <iostream>
// STRING
#include <string>
// MAP
#include <map>
// VECTOR
#include <vector>
// PAIR
#include <utility>

using namespace std;

int main()
{
  int n_linhas;
  int d;
  string str;
  vector<int> _numeros;
  vector<char> _senha_codificada;
  map<char, pair<int, int>> _traducao;
  vector<pair<int, int>> _lista_codificada;
  vector<vector<pair<int, int>>> _lista_comparacao;

  getline(cin, str);
  n_linhas = stoi(str);

  for (int i = 0; i < n_linhas; i++)
  {
    getline(cin, str);

    for (char aux : str)
    {
      if (aux != ' ')
      {
        if (aux < 'A')
        {
          _numeros.push_back(aux - '0');
        }
        else
        {
          _senha_codificada.push_back(aux);
        }
      }
    }
    char _letras = 'A';

    for (int i = 0; i < _numeros.size(); i += 2)
    {
      _traducao[_letras] = make_pair(_numeros[i], _numeros[i + 1]);
      _letras++;
    }

    for (char letra : _senha_codificada)
    {
      _lista_codificada.push_back(_traducao[letra]);
    }

    _lista_comparacao.push_back(_lista_codificada);
    _numeros.clear();
    _senha_codificada.clear();
    _lista_codificada.clear();
  }

  for (int j = 0; j < 6; j++)
  {
    for (int i = 0; i < (n_linhas - 1); i++)
    {
      if (_lista_comparacao[i][j].first == _lista_comparacao[i + 1][j].second &&
              _lista_comparacao[i][j].second != _lista_comparacao[i + 1][j].first ||
          _lista_comparacao[i][j].first == _lista_comparacao[i + 1][j].first &&
              _lista_comparacao[i][j].second != _lista_comparacao[i + 1][j].second)
      {
        d = _lista_comparacao[i][j].first;
      }
      else
      {
        d = _lista_comparacao[i][j].second;
      }
    }
    cout << d << " ";
  }

  cout << endl;

  return 0;
}