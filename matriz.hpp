#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <iostream>

using namespace std;

class Matriz
{
private:
  int colunas, linhas;

public:
  Matriz(int colunas, int linhas);

  Matriz operator+(Matriz &other);

  int get_colunas();
  int get_linhas();

  int set_colunas(int colunas);
  int set_linhas(int linhas);
};

void operator<<(ostream &os, Matriz &matriz);

#endif