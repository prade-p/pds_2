#include <iostream>
#include <vector>
#include <string>

#include "acai.hpp"
using namespace std;

Acai::Acai(int tam, vector<string> &comple, int quant)
{
  this->_tamanho = tam;
  this->_complementos = comple;
  this->_quantidade = quant;
}

float Acai::calcPreco()
{
  float valor = 0;
  valor = this->_tamanho * 0.02 + this->_complementos.size() * 2;
  return valor;
}

string Acai::descricao() const
{
  string resumo;
  resumo = to_string(this->_quantidade) + "X açai " + to_string(this->_tamanho) + "ml com ";

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