#ifndef ESTOQUE_CPP
#define ESTOQUE_CPP

#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"

Estoque::Estoque()
{
  geladeiras;
  fogoes;
};

void Estoque::armazena_geladeira(int capacidade, int portas)
{
  Geladeira nova_geladeira = Geladeira(capacidade, portas);
  geladeiras.push_back(nova_geladeira);
};

void Estoque::vende_geladeira(int capacidade, int portas)
{
  for (int i = 0; i < geladeiras.size(); i++)
  {
    if (geladeiras[i].Get_Capcidade() == capacidade && geladeiras[i].Get_Portas() == portas)
    {
      geladeiras.erase(geladeiras.begin() + i);
    }
  }
};

void Estoque::armazena_fogao(int queimadores, int capacidade)
{
  Fogao novo_fogao = Fogao(queimadores, capacidade);
  fogoes.push_back(novo_fogao);
};

void Estoque::vende_fogao(int queimadores, int capacidade)
{
  for (int i = 0; i < fogoes.size(); i++)
  {
    if (fogoes[i].Get_Capacidade() == capacidade && fogoes[i].Get_Queimadores() == queimadores)
    {
      fogoes.erase(fogoes.begin() + i);
    }
  }
};

void Estoque::exibe_geladeiras()
{
  for (int i = 0; i < geladeiras.size(); i++)
  {
    cout << "G " << geladeiras[i].Get_Capcidade() << " " << geladeiras[i].Get_Portas() << endl;
  }
};

void Estoque::exibe_fogoes()
{
  for (int i = 0; i < fogoes.size(); i++)
  {
    cout << "F " << fogoes[i].Get_Queimadores() << " " << fogoes[i].Get_Capacidade() << endl;
  }
};

int Estoque::quantidade_geladeiras()
{
  return geladeiras.size();
};

int Estoque::quantidade_fogoes()
{
  return fogoes.size();
};

#endif