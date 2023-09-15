#include <iostream>  // std::cout, std::endl
#include <iomanip>   // std::setw
#include <map>       // std::map
#include <queue>     // std::priority_queue
#include <utility>   // std::pair
#include <cctype>    // std::tolower
#include <algorithm> // std::transform
#include <string>

using namespace std;

class Time
{
public:
  string nome;
  vector<int> estatisticas;

  Time(string nome, vector<int> estatisticas)
      : nome(nome), estatisticas(estatisticas) {}

  bool operator<(const Time &aux) const
  {
    string nome_a = nome;
    string nome_b = aux.nome;

    // Ordenando por nome
    transform(nome_a.begin(), nome_a.end(), nome_a.begin(), [](unsigned char c)
              { return tolower(c); });
    transform(nome_b.begin(), nome_b.end(), nome_b.begin(), [](unsigned char c)
              { return tolower(c); });

    // Casos de ordenação

    // pontuacao
    if (estatisticas[0] != aux.estatisticas[0])
    {
      return estatisticas[0] < aux.estatisticas[0];
    }
    // saldo de gols
    if (estatisticas[4] != aux.estatisticas[4])
    {
      return estatisticas[4] < aux.estatisticas[4];
    }
    // gols marcados
    if (estatisticas[2] != aux.estatisticas[2])
    {
      return estatisticas[2] < aux.estatisticas[2];
    }

    // nome
    return nome_a > nome_b;
  }
};

int main()
{
  int t, j;
  map<string, vector<int>> time_pontuacao;

  cin >> t >> j;

  // iniciando times
  for (int i = 0; i < t; i++)
  {
    string aux;
    vector<int> iniciador = {0, 0, 0, 0, 0};
    cin >> aux;
    time_pontuacao.insert(make_pair(aux, iniciador));
  }

  // partida
  for (int i = 0; i < j; i++)
  {
    string time_1, time_2, aux;
    int gol_1, gol_2;
    cin >> time_1 >> gol_1 >> aux >> gol_2 >> time_2;

    if (gol_1 > gol_2)
    {
      time_pontuacao[time_1][0] += 3;
    }
    else if (gol_1 == gol_2)
    {
      time_pontuacao[time_1][0]++;
      time_pontuacao[time_2][0]++;
    }
    else
    {
      time_pontuacao[time_2][0] += 3;
    }

    // jogos disputados - add
    time_pontuacao[time_1][1]++;
    time_pontuacao[time_2][1]++;

    // numero de gols marcados
    time_pontuacao[time_1][2] += gol_1;
    time_pontuacao[time_2][2] += gol_2;

    // numero de gols sofridos
    time_pontuacao[time_1][3] += gol_2;
    time_pontuacao[time_2][3] += gol_1;

    // saldo de gol
    time_pontuacao[time_1][4] = time_pontuacao[time_1][2] - time_pontuacao[time_1][3];
    time_pontuacao[time_2][4] = time_pontuacao[time_2][2] - time_pontuacao[time_2][3];
  }

  priority_queue<Time> times;

  for (auto &_time : time_pontuacao)
  {
    string nome = _time.first;
    vector<int> estatisticas = _time.second;
    times.push(Time(nome, estatisticas));
  }

  int posicao = 1;
  int contador_grupo = 1;
  int posicao_grupo = 1;
  Time time_anterior("", {});

  while (!times.empty())
  {
    Time time = times.top();
    times.pop();

    if (time.estatisticas != time_anterior.estatisticas)
    {
      posicao_grupo = posicao;
      contador_grupo = 1;
    }

    if (contador_grupo == 1)
    {
      cout << setw(3) << posicao_grupo << ".";
    }
    else
    {
      cout << setw(4) << " ";
    }

    cout << setw(16) << time.nome;
    for (int aux : time.estatisticas)
    {
      cout << setw(4) << aux;
    }

    float porcentagem = ((float)time.estatisticas[0] / (3 * (float)time.estatisticas[1])) * 100;

    if (time.estatisticas[1] != 0)
    {
      cout << setw(7) << fixed << setprecision(2) << porcentagem;
    }
    else
    {
      cout << setw(7) << "N/A";
    }
    cout << endl;

    time_anterior = time;
    posicao++;
    contador_grupo++;
  }

  return 0;
}