#include <iostream>
#include <vector>
#include <string>

#include "cachorro_quente.hpp"

using namespace std;

CachorroQuente::CachorroQuente(int sal, vector<string> &comple, bool pren, int quant)
{
  this->_num_salsichas = sal;
  this->_complementos = comple;
  this->_prensado = pren;
  this->_quantidade = quant;
}

float CachorroQuente::calcPreco()
{
  float resultado;
  resultado = 5.0;
  if (this->_prensado == 1)
  {
    resultado += 0.5;
  }
  resultado += (this->_num_salsichas * 1.5) + (this->_complementos.size() * 1.0);
  return resultado;
}

string CachorroQuente::descricao() const
{
  string resumo;
  resumo = to_string(this->_quantidade) + "X cachorro-quente ";
  if (this->_prensado == true)
  {
    resumo += "prensado ";
  }
  resumo += "com " + to_string(this->_num_salsichas) + " salsicha(s), ";

  for (int i = 0; i < this->_complementos.size(); i++)
  {
    string aux = this->_complementos[i];
    if (i == this->_complementos.size() - 1)
    {
      resumo = resumo + aux + ".";
    }
    else
    {
      resumo = resumo + aux + ", ";
    }
  }

  return resumo;
}