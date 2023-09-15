#ifndef GELADEIRA_CPP
#define GELADEIRA_CPP

#include "geladeira.hpp"

// Adicione seus metodos / construtores aqui
Geladeira::Geladeira(int _capacidade, int _portas)
{
  capacidade_em_litros = _capacidade;
  numero_de_portas = _portas;
}

int Geladeira::Get_Capcidade()
{
  return capacidade_em_litros;
}

int Geladeira::Get_Portas()
{
  return numero_de_portas;
}
#endif