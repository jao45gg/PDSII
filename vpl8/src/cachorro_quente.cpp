#ifndef CACHORRO_QUENTE_CPP
#define CACHORRO_QUENTE_CPP

#include "cachorro_quente.hpp"
#include <sstream>

using namespace std;

CachorroQuente::CachorroQuente(int num_salsichas, vector<string> &complementos,
                               bool prensado, int qtd)
{
    _num_salsichas = num_salsichas;
    _complementos = complementos;
    _prensado = prensado;
    _quantidade = qtd;
    _valor_unitario = calcPreco();
}

float CachorroQuente::calcPreco()
{
    float preco = 0;

    preco += 1 * _complementos.size();

    preco += 5 + (1.5 * _num_salsichas) + (0.5 * _prensado);

    return preco;
}

string CachorroQuente::descricao() const
{
    ostringstream str1;
    str1 << getQtd();

    string _descricao;
    _descricao = str1.str();
    if(_prensado)
        _descricao += "X cachorro-quente prensado com ";
    else
        _descricao += "X cachorro-quente com ";

    ostringstream str2;
    str2 << _num_salsichas;
    _descricao += (str2.str() + " salsicha(s), ");

    for (int i = 0, ie = _complementos.size(); i < ie; i++)
    {
        if (i != ie - 1)
            _descricao += _complementos.at(i) + ", ";
    }

    _descricao += _complementos.back() + '.';

    return _descricao;
}

#endif