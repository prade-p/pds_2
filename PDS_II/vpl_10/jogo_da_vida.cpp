#include "jogo_da_vida.hpp"

using namespace std;

// Inicializa vivas_ como um vetor com l elementos.
// Cada elemento, por sua vez, é um vetor com c elementos iguais a false.
JogoDaVida::JogoDaVida(int l, int c)
    : vivas_(l, std::vector<bool>(c, false))
{
}

bool JogoDaVida::viva(int i, int j)
{
  return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j)
{
  vivas_[i][j] = false;
}
void JogoDaVida::Reviver(int i, int j)
{
  if (i < 0 || j < 0 || i >= this->linhas() || j >= this->colunas())
  {
    throw ExcecaoCelulaInvalida(i, j);
  }
  else
  {
    vivas_[i][j] = true;
  }
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y)
{
  int vizinhas_vivas = 0;
  for (int i : {x - 1, x, x + 1})
  {
    for (int j : {y - 1, y, y + 1})
    {
      if (i != x || j != y)
      { // Não conta a própria célula [x, y].
        int i_circular = (i + linhas()) % linhas();
        int j_circular = (j + colunas()) % colunas();
        if (viva(i_circular, j_circular))
        {
          vizinhas_vivas++;
        }
      }
    }
  }
  return vizinhas_vivas;
}

void JogoDaVida::ExecutarProximaIteracao()
{
  JogoDaVida novo(linhas(), colunas()); // Cria um novo objeto, com todas as
                                        // células mortas.
  for (int i = 0; i < linhas(); i++)
  {
    for (int j = 0; j < colunas(); j++)
    {
      int n = NumeroDeVizinhasVivas(i, j);
      if (n == 3 || (n == 2 && viva(i, j)))
      {
        novo.Reviver(i, j);
      }
    }
  }
  *this = novo;
}

void JogoDaVida::Executar(int n)
{
  for (int i = 0; i < n; i++)
  {
    ExecutarProximaIteracao();
  }
}

ExcecaoCelulaInvalida::ExcecaoCelulaInvalida(int linha, int coluna)
{
  this->_linha = linha;
  this->_coluna = coluna;

  this->_mensagem_erro = "Célula (" + to_string(linha) + ", " + to_string(coluna) + ") não é válida. Deseja continuar e ignorá-la? (s/n)?";
}

const char *ExcecaoCelulaInvalida::what() const noexcept
{
  return this->_mensagem_erro.c_str();
}