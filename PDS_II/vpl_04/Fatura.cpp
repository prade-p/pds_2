#include "Fatura.hpp"
#include <iostream>
using namespace std;

Fatura::Fatura(int codigo, double valor)
{
  _codigo = codigo;
  _valor = valor;
}

void Fatura::imprimir_dados()
{
  cout << _codigo << " " << _valor << endl;
}

double Fatura::getValor()
{
  return _valor;
}