#ifndef GELADEIRA_CPP
#define GELADEIRA_CPP

#include "geladeira.hpp"

Geladeira::Geladeira(int _cap_em_litros, int _num_de_portas)
{
    capacidade_em_litros = _cap_em_litros;
    numero_de_portas = _num_de_portas;
}

int Geladeira::get_capacidade()
{
    return this->capacidade_em_litros;
}

int Geladeira::get_num_portas()
{
    return this->numero_de_portas;
}

#endif
