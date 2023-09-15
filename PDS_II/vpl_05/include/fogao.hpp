#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao
{
private:
  // Adicione suas variaveis globais aqui
  int numero_de_queimadores;
  int capacidade_forno;

public:
  // Adicione a assinatura dos seus metodos / construtores aqui
  Fogao(int _queimadores, int _capacidade);
  int Get_Queimadores();
  int Get_Capacidade();
};

#endif