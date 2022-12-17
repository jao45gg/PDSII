#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao
{
private:
    int numero_de_queimadores;
    int capacidade_forno;

public:
    Fogao(int _queimadores, int _capacidade);
    int get_num_queimadores();
    int get_capacidade_forno();
};

#endif