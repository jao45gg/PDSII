#ifndef PEDIDO_CPP
#define PEDIDO_CPP

#include "pedido.hpp"
#include <sstream>

using namespace std;

Pedido::~Pedido()
{
    for (int i = 0, ie = _produtos.size(); i < ie; i++)
    {
        delete _produtos.front();
        _produtos.pop_front();
    }
}

void Pedido::adicionaProduto(Produto *p)
{
    _produtos.push_back(p);
}

float Pedido::calculaTotal() const
{
    float valor = 0;

    for (auto i : _produtos)
    {
        valor += (i->getValor() * i->getQtd());
    }

    return valor;
}

string Pedido::resumo() const
{
    string resumo;
    ostringstream str1;
    str1 << endl;
    for (auto i : _produtos)
    {
        resumo += (i->descricao() + str1.str());
    }
    resumo += _endereco + str1.str();

    return resumo;
}

void Pedido::setEndereco(const string &endereco)
{
    _endereco = "Endereço: " + endereco;
}

#endif