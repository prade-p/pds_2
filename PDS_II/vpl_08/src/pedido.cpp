#include <iostream>
#include <vector>
#include <string>

#include "pedido.hpp"
using namespace std;

void Pedido::adicionaProduto(Produto *p)
{
  this->_produtos.push_back(p);
}

float Pedido::calculaTotal() const
{
  float total = 0;
  for (Produto *aux : this->_produtos)
  {
    total += aux->calcPreco() * aux->getQtd();
  }
  return total;
}

string Pedido::resumo() const
{
  string final;
  for (Produto *aux : this->_produtos)
  {
    final += aux->descricao();
    final += "\n";
  }
  final += "Endereço: " + this->_endereco;
  return final;
}

void Pedido::setEndereco(const string &ende)
{
  this->_endereco = ende;
}

Pedido::~Pedido()
{
  for (Produto *aux : this->_produtos)
  {
    delete (aux);
  }
}