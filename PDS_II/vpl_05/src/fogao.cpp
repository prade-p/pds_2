#ifndef FOGAO_CPP
#define FOGAO_CPP

#include "fogao.hpp"

// Adicione seus metodos / construtores aqui
Fogao::Fogao(int _queimadores, int _capacidade)
{
  numero_de_queimadores = _queimadores;
  capacidade_forno = _capacidade;
}

int Fogao::Get_Capacidade()
{
  return capacidade_forno;
}

int Fogao::Get_Queimadores()
{
  return numero_de_queimadores;
}

#endif