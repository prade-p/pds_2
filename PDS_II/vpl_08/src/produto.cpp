#include <iostream>
#include <vector>
#include <string>

#include "produto.hpp"

using namespace std;

int Produto::getQtd() const
{
  return this->_quantidade;
}

float Produto::getValor() const
{
  return this->_valor_unitario;
}