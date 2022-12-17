#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP

#include <iostream>

class Geladeira
{
private:
    int capacidade_em_litros;
    int numero_de_portas;

public:
    Geladeira(int _cap_em_litros, int _num_de_portas);
    int get_capacidade();
    int get_num_portas();
};

#endif