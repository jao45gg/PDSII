#ifndef fatura_hpp
#define fatura_hpp

#include <iostream>

struct Fatura
{
    int _id;
    double _valor;
    Fatura *anterior;
    Fatura *proximo;

    Fatura(int id, double valor);

    void imprimir_dados();

    double getValor();
};

#endif