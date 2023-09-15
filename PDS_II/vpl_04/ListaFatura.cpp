#include "ListaFatura.hpp"
#include <iostream>
using namespace std;

no_fatura::no_fatura(Fatura *fatura)
{
  _proximo = nullptr;
  _anterior = nullptr;
  _fatura = fatura;
}

ListaFatura::ListaFatura()
{
  _inicio = nullptr;
  _final = nullptr;
}

void ListaFatura::insere_fatura(Fatura *fatura)
{
  no_fatura *nova_fatura = new no_fatura(fatura);
  if (_inicio == nullptr)
  {
    _inicio = nova_fatura;
    _final = nova_fatura;
  }
  else
  {
    if (nova_fatura->_fatura->getValor() > _inicio->_fatura->getValor())
    {
      nova_fatura->_proximo = _inicio;
      _inicio->_anterior = nova_fatura;
      _inicio = nova_fatura;
    }
    else
    {
      no_fatura *atual = _inicio;
      while (nova_fatura->_fatura->getValor() < atual->_fatura->getValor())
      {
        atual = atual->_proximo;
        if (atual == nullptr)
        {
          _final->_proximo = nova_fatura;
          nova_fatura->_anterior = _final;
          _final = nova_fatura;
          return;
        }
      }
      nova_fatura->_anterior = atual->_anterior;
      nova_fatura->_proximo = atual;
      atual->_anterior->_proximo = nova_fatura;
      atual->_anterior = nova_fatura;
    }
  }
}

Fatura *ListaFatura::proxima_fatura()
{
  if (_inicio == nullptr)
  {
    return nullptr;
  }
  else
  {
    no_fatura *maior_valor = nullptr;
    maior_valor = _inicio;
    if (_inicio->_proximo == nullptr)
    {
      _inicio = nullptr;
    }
    else
    {
      _inicio->_proximo->_anterior = nullptr;
      _inicio = _inicio->_proximo;
    }
    return maior_valor->_fatura;
  }
}

void ListaFatura::imprimir_lista()
{
  no_fatura *atual = _inicio;

  while (atual != nullptr)
  {
    atual->_fatura->imprimir_dados();
    atual = atual->_proximo;
  }
}