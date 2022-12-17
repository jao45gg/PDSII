#ifndef PRODUTO_CPP
#define PRODUTO_CPP

#include "produto.hpp"
#include <sstream>

using namespace std;

int Produto::getQtd() const
{
    return _quantidade;
}

float Produto::getValor() const
{
    return _valor_unitario;
}

string Produto::descricao() const 
{
    ostringstream str1;
    str1 << getQtd();
    string _descricao = str1.str();
    return _descricao + 'X';
}

float Produto::calcPreco()
{
    return getQtd() * getValor();
}

#endif