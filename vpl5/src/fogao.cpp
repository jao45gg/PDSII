#ifndef FOGAO_CPP
#define FOGAO_CPP

#include "fogao.hpp"

Fogao::Fogao(int _queimadores, int _capacidade)
{
    numero_de_queimadores = _queimadores;
    capacidade_forno = _capacidade;
}

int Fogao::get_num_queimadores()
{
    return this->numero_de_queimadores;
}

int Fogao::get_capacidade_forno()
{
    return this->capacidade_forno;
}

#endif
