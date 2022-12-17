#ifndef ESTOQUE_CPP
#define ESTOQUE_CPP

#include <iostream>
#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"

using namespace std;

Estoque::Estoque() {}

void Estoque::armazena_geladeira(int capacidade, int portas)
{
    if (geladeiras.size() < 100)
        geladeiras.push_back(Geladeira(capacidade, portas));
}

void Estoque::vende_geladeira(int capacidade, int portas)
{
    unsigned int i = 0;
    while (geladeiras.size() > i)
    {
        if (geladeiras.at(i).get_capacidade() == capacidade && geladeiras.at(i).get_num_portas() == portas)
        {
            geladeiras.erase(geladeiras.begin() + i);
            break;
        }
        i++;
    }
}

void Estoque::armazena_fogao(int queimadores, int capacidade)
{
    if (fogoes.size() < 100)
        fogoes.push_back(Fogao(queimadores, capacidade));
}

void Estoque::vende_fogao(int queimadores, int capacidade)
{
    unsigned int i = 0;
    while (fogoes.size() > i)
    {
        if (fogoes.at(i).get_num_queimadores() == queimadores && fogoes.at(i).get_capacidade_forno() == capacidade)
        {
            fogoes.erase(fogoes.begin() + i);
            break;
        }
        i++;
    }
}

void Estoque::exibe_geladeiras()
{
    for (Geladeira g : geladeiras)
    {
        cout << "G" << " " << g.get_capacidade() << " " << g.get_num_portas() << endl;
    }
}

void Estoque::exibe_fogoes()
{
    for (Fogao f : fogoes)
    {
        cout << "F" << " " << f.get_num_queimadores() << " " <<f.get_capacidade_forno() << endl;
    }
}

int Estoque::quantidade_geladeiras()
{
    return geladeiras.size();
}

int Estoque::quantidade_fogoes()
{
    return fogoes.size();
}

#endif
