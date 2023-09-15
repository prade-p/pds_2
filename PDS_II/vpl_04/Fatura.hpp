#ifndef FATURA_H
#define FATURA_H
#include <iostream>

struct Fatura
{
  int _codigo;
  double _valor;
  Fatura(int codigo, double valor);
  void imprimir_dados();
  double getValor();
};

#endif