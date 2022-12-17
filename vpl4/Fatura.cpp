#ifndef fatura_cpp
#define fatura_cpp

#include <iostream>
#include "Fatura.hpp"

using namespace std;

Fatura::Fatura(int id, double valor)
{
    _id = id;
    _valor = valor;
    anterior = nullptr;
    proximo = nullptr;
}

void Fatura::imprimir_dados()
{
    cout << _id << " " << _valor << endl;
}

double Fatura::getValor()
{
    return _valor;
}

#endif