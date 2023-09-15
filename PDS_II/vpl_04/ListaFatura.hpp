#ifndef LISTA_FATURA_H
#define LISTA_FATURA_H
#include "Fatura.hpp"
#include <iostream>

struct no_fatura
{
  Fatura *_fatura;
  no_fatura *_proximo;
  no_fatura *_anterior;
  no_fatura(Fatura *fatura);
};

struct ListaFatura
{
  no_fatura *_inicio;
  no_fatura *_final;
  ListaFatura();
  void insere_fatura(Fatura *fatura);
  Fatura *proxima_fatura();
  void imprimir_lista();
};

#endif