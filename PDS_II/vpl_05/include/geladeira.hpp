#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP

#include <iostream>

class Geladeira
{
private:
  // Adicione suas variaveis globais aqui
  int capacidade_em_litros;
  int numero_de_portas;

public:
  // Adicione a assinatura dos seus metodos / construtores aqui
  Geladeira(int _capacidade, int _portas);
  int Get_Capcidade();
  int Get_Portas();
};

#endif