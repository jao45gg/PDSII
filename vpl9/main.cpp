#include <iostream>  // std::cout, std::endl
#include <iomanip>   // std::setw
#include <cctype>    // std::tolower
#include <algorithm> // std::sort
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  class time
  {
  private:
    string nome;
    int posicao;
    int num_pontos;
    int num_jogos;
    int num_gols_marcados;
    int num_gols_sofridos;
    int saldo_gols;
    float porcentagem_pts;

  public:
    time(string _nome)
    {
      nome = _nome;
      posicao = 0;
      num_pontos = 0;
      num_jogos = 0;
      num_gols_marcados = 0;
      num_gols_sofridos = 0;
      saldo_gols = 0;
      porcentagem_pts = 0;
    }

    void setPosicao(int _posicao)
    {
      posicao = _posicao;
    }

    void setNum_Pontos(int resultado)
    {
      if (resultado == 1)
        num_pontos++;
      else if (resultado == 2)
        num_pontos += 3;
    }

    void setJogos()
    {
      num_jogos++;
    }

    void setSaldo_Gols()
    {
      saldo_gols = num_gols_marcados - num_gols_sofridos;
    }

    void setGols_Marcados(int _num_gols_marcados)
    {
      num_gols_marcados += _num_gols_marcados;
    }

    void setGols_Sofridos(int _num_gols_sofridos)
    {
      num_gols_sofridos += _num_gols_sofridos;
    }

    void setPorcentagem_Pontos()
    {
      float n1,n2;
      n1 = num_pontos * 100;
      n2 = num_jogos * 3;
      porcentagem_pts = n1 / n2;
    }

    void setNome(string _nome)
    {
      nome = _nome;
    }

    string getNome()
    {
      return nome;
    }

    int getmarcados()
    {
      return num_gols_marcados;
    }

    int getsofridos()
    {
      return num_gols_sofridos;
    }

    int getsaldo()
    {
      return saldo_gols;
    }

    int getpontos()
    {
      return num_pontos;
    }

    int getjogos()
    {
      return num_jogos;
    }

    int getposicao()
    {
      return posicao;
    }

    float getporcentagem()
    {
      return porcentagem_pts;
    }
  };

  struct comparar {
  bool operator() (time i,time j) { return (i.getposicao() < j.getposicao());}
  } comparador;

  vector<time> times;
  vector<string> nomes;
  int num_times, num_jogos;

  cin >> num_times >> num_jogos;

  for (int i = 0, ie = num_times; i < ie; i++)
  {
    string nome_time;
    bool controle = 1;
    cin >> nome_time;
    for (int j = 0, je = nomes.size(); j < je; j++)
    {
      if (nome_time == nomes[j])
        controle = 0;
    }
    if (controle)
    {
      nomes.push_back(nome_time);
    }
  }

  vector<string> nomes_ordenados(nomes);

  for (int i = 0, ie = nomes_ordenados.size(); i < ie; i++)
  {
    char c;
    int contador = 0;
    string str = nomes_ordenados[i];
    while (str[contador])
    {
      c = str[contador];
      str[contador] = tolower(c);
      contador++;
    }
    nomes_ordenados[i] = str;
    contador = 0;
  }

  sort(nomes_ordenados.begin(), nomes_ordenados.end());

  for (int i = 0, ie = num_times; i < ie; i++)
  {
    times.push_back(nomes_ordenados[i]);
  }

  for (int i = 0, ie = num_jogos; i <= ie; i++)
  {

    string line, tmp, _time1, _time2;
    int marcados = 0, sofridos = 0;

    getline(cin, line);
    std::istringstream iss(line);
    std::getline(iss, _time1, ' ');

    char c;
    int contador = 0;
    string str = _time1;
    while (str[contador])
    {
      c = str[contador];
      str[contador] = tolower(c);
      contador++;
    }
    _time1 = str;
    contador = 0;

    std::getline(iss, tmp, ' ');
    std::istringstream(tmp) >> marcados;

    std::getline(iss, tmp, ' ');
    std::getline(iss, tmp, ' ');
    std::istringstream(tmp) >> sofridos;

    std::getline(iss, tmp, ' ');
    std::istringstream(tmp) >> _time2;

    str = _time2;
    while (str[contador])
    {
      c = str[contador];
      str[contador] = tolower(c);
      contador++;
    }
    _time2 = str;

    for (int k = 0, ke = times.size(); k < ke && i > 0; k++)
    {

      if (_time1 == times[k].getNome())
      {
        times.at(k).setGols_Marcados(marcados);
        times.at(k).setGols_Sofridos(sofridos);
        times.at(k).setJogos();
        if (marcados > sofridos)
          times.at(k).setNum_Pontos(2);
        else if (marcados == sofridos)
          times.at(k).setNum_Pontos(1);
      }
      else if (_time2 == times[k].getNome())
      {
        times.at(k).setGols_Marcados(sofridos);
        times.at(k).setGols_Sofridos(marcados);
        times.at(k).setJogos();
        if (sofridos > marcados)
          times.at(k).setNum_Pontos(2);
        else if (marcados == sofridos)
          times.at(k).setNum_Pontos(1);
      }
      if (k == times.size() - 1)
      {
        for (int l = 0, le = times.size(); l < le; l++)
        {
          times[l].setSaldo_Gols();
          times[l].setPorcentagem_Pontos();
        }
      }
    }
  }


  int posicao = 1;
  bool test = true;
  for (int i = 0, ie = times.size(); i < ie; i++)
  {
    int caso_especial = 0;

    for (int j = i + 1, je = times.size(); j < je; j++)
    {
      if (times[i].getpontos() > times[j].getpontos() && !(times[i].getposicao() != 0))
      {
        times[i].setPosicao(posicao);
        caso_especial++;
      }
      else if (times[i].getpontos() == times[j].getpontos())
      {
        if (times[i].getsaldo() > times[j].getsaldo() && !(times[i].getposicao() != 0))
        {
          times[i].setPosicao(posicao);
          caso_especial++;
        }
        else if (times[i].getsaldo() == times[j].getsaldo())
        {
          if (times[i].getmarcados() > times[j].getmarcados() && !(times[i].getposicao() != 0))
          {
            times[i].setPosicao(posicao);
            caso_especial++;
          }
          else if (times[i].getmarcados() == times[j].getmarcados())
          {
            if (!(times[i].getposicao() != 0) && !(times[j].getposicao() != 0))
            {
              times[i].setPosicao(posicao);
              times[j].setPosicao(posicao);
              caso_especial += 2;
            }
            else if (!(times[i].getposicao() != 0))
            {
              times[i].setPosicao(posicao);
              caso_especial++;
            }
            else if (!(times[j].getposicao() != 0))
            {
              times[j].setPosicao(posicao);
              caso_especial++;
            }
          }
          else if(!(times[i].getposicao() != 0))
          {
            if(!(times[j].getposicao() != 0))
            {
              times[i].setPosicao(posicao+1);
            }
            else
            {
              times[i].setPosicao(posicao);
              caso_especial++;
            }
          }
        }
      }
    }
    posicao += caso_especial;
    if(!(times[i].getposicao() != 0) && test)
    {
      test = false;
      times[i].setPosicao(times.size());
    }
    else if (!(times[i].getposicao() != 0))
      times[i].setPosicao(posicao);
  }

  for (int i = 0, ie = num_times; i < ie; i++)
  {
    char c;
    int contador = 0;
    string str = nomes[i];
    while (str[contador])
    {
      c = str[contador];
      str[contador] = tolower(c);
      contador++;
    }
    contador = 0;
    for (int j = 0, je = num_times; j < je; j++)
    {
      if (str == times[j].getNome())
        times[j].setNome(nomes[i]);
      contador = 0;
    }
  }

  sort(times.begin(), times.end(), comparador);

  for (int i = 0, ie = num_times; i < ie; i++)
  {
    if (times[i].getposicao() == times[i - 1].getposicao())
    {
      cout << setw(18) << times[i].getNome() << setw(4) << times[i].getpontos() << setw(4) << times[i].getjogos() << setw(4) << times[i].getmarcados()
      << setw(4) << times[i].getsofridos() << setw(4) << times[i].getsaldo();
      cout << fixed;
      cout.precision(2);
      if(times[i].getjogos() == 0)
        cout << "  " << "N/A" << endl;
      else 
        cout << "  " << times[i].getporcentagem() << endl;
    }
    else
    {
      cout << times[i].getposicao() << "." << setw(16) << times[i].getNome() << setw(4) << times[i].getpontos() << setw(4) << times[i].getjogos() << setw(4) << times[i].getmarcados()
      << setw(4) << times[i].getsofridos() << setw(4) << times[i].getsaldo();
      cout << fixed;
      cout.precision(2);
      if(times[i].getjogos() == 0)
        cout << "  " << "N/A" << endl;
      else 
        cout << "  " << times[i].getporcentagem() << endl;
    }    
  }

  return 0;
}

  // for (int i = 0, ie = times.size(); i < ie; i++)
  // {
  //   bool controle = 1;
  //   int posicao = 0;
    
  //   if(i == times.size() - 1)
  //   {
  //     times[i].setPosicao(i + 1);
  //     break;
  //   }

  //   for (int j = times.size() - 1, je = 0; j >= je && controle; j--)
  //   {
  //     if(times[i].getpontos() > times[j].getpontos())
  //       posicao = i;
  //     else if(times[i].getpontos() == times[j].getpontos())
  //     {
  //       if(times[i].getsaldo() > times[j].getsaldo())
  //         posicao = i;
  //       else if(times[i].getsaldo() == times[j].getsaldo())
  //       {
  //         if(times[i].getmarcados() > times[j].getmarcados())
  //           posicao = i;
  //         else if (times[i].getmarcados() == times[j].getmarcados())
  //       }
  //     }


  //   }
  //   controle = 1;
  // }