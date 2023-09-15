#include <iostream>
#include <vector>
#include <string>

#include "venda.hpp"
using namespace std;

void Venda::adicionaPedido(Pedido *p)
{
  this->_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const
{
  int qnt_pedidos = 1;
  float preco_total = 0;
  int pedidos = this->_pedidos.size();

  for (Pedido *aux : this->_pedidos)
  {
    preco_total += aux->calculaTotal();
  }

  for (Pedido *aux : this->_pedidos)
  {
    cout << "Pedido " << qnt_pedidos << endl;
    cout << aux->resumo() << endl;
    qnt_pedidos++;
  }

  cout << "Relatorio de Vendas" << endl;
  cout << "Total de vendas: R$" << fixed << setprecision(2) << preco_total << endl;
  cout << "Total de pedidos: " << pedidos << endl;
}

Venda::~Venda()
{
  for (Pedido *aux : this->_pedidos)
  {
    delete (aux);
  }
}