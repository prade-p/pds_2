// NÃO ALTERE ESSA LINHA
#include "avaliacao.hpp"
#include "Fatura.hpp"
#include "ListaFatura.hpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  ListaFatura lista;
  string linha;
  int cod;
  double val;
  char caso;

  while (getline(cin, linha))
  {
    stringstream stream_string(linha);
    stream_string >> caso >> cod >> val;
    switch (caso)
    {
    case 'f':
    {
      lista.insere_fatura(new Fatura(cod, val));
      break;
    }
    case 'r':
    {
      Fatura *fatura = lista.proxima_fatura();
      if (fatura != nullptr)
      {
        fatura->imprimir_dados();
      }
      break;
    }
    case 'p':
    {
      lista.imprimir_lista();
      break;
    }
    case 'a':
    {
      avaliacao_basica();
      break;
    }
    default:
    {
      cout << "----------" << endl;
      break;
    }
    }
  }

  return 0;
}