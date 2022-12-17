#ifndef ACAI_CPP
#define ACAI_CPP

#include "acai.hpp"
#include <sstream>

Acai::Acai(int tamanho, vector<string> &complementos, int qtd)
{
    _quantidade = qtd;
    _tamanho = tamanho;
    _complementos = complementos;
    _valor_unitario = calcPreco();
}

float Acai::calcPreco()
{
    return (0.02 * _tamanho) + (2 * _complementos.size());
}

string Acai::descricao() const
{
    ostringstream str1;
    str1 << getQtd();

    string _descricao = str1.str();
    _descricao += "X açai ";

    ostringstream str2;
    str2 << _tamanho;
    _descricao += (str2.str() + "ml com ");

    for (int i = 0, ie = _complementos.size(); i < ie; i++)
    {
        if (i != ie - 1)
            _descricao += _complementos.at(i) + ", ";
    }

    _descricao += _complementos.back() + '.';

    return _descricao;
}

#endif