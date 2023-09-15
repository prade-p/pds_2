#include <iostream>
#include <vector>
#include <string>

#include "pizza.hpp"
using namespace std;

Pizza::Pizza(const string &sabor, int pedacos, bool borda, int quant)
{
  this->_sabor = sabor;
  this->_num_pedacos = pedacos;
  this->_quantidade = quant;
  this->_borda_recheada = borda;
}

float Pizza::calcPreco()
{
  float valor = 0.0;
  if (this->_sabor.find("especial") != string::npos)
  {
    valor += 8.0;
  }
  valor += (this->_num_pedacos * 5.0) + (this->_borda_recheada * 10.0);
  return valor;
}

string Pizza::descricao() const
{
  string resumo;
  resumo = to_string(this->_quantidade) + "X pizza " + this->_sabor + ", " + to_string(this->_num_pedacos) + " pedaços";

  if (this->_borda_recheada == true)
  {
    resumo += " e borda recheada.";
  }
  else
  {
    resumo += " sem borda recheada.";
  }

  return resumo;
}