#ifndef PIZZA_CPP
#define PIZZA_CPP

#include "pizza.hpp"
#include <sstream>

using namespace std;

Pizza::Pizza(const string sabor, int pedacos,
             bool borda_recheada, int qtd)
{
    _sabor = sabor;
    _num_pedacos = pedacos;
    _borda_recheada = borda_recheada;
    _quantidade = qtd;
    _valor_unitario = calcPreco();
}

float Pizza::calcPreco()
{
    float preco = 0;

    preco += (5 * _num_pedacos) + (10 * _borda_recheada);

    size_t especial = _sabor.find("especial");
    if (especial != string::npos)
        preco += 8;

    return preco;
}

string Pizza::descricao() const
{
    ostringstream str1;
    str1 << getQtd();

    string _descricao = str1.str();
    _descricao += "X pizza " + _sabor;

    ostringstream str2;
    str2 << _num_pedacos;
    
    _descricao += ", " + (str2.str() + " pedaços ");
    

    if (_borda_recheada)
        _descricao += "e borda recheada.";
    else
        _descricao += "sem borda recheada.";

    return _descricao;
}

#endif