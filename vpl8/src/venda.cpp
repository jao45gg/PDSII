#ifndef VENDA_CPP
#define VENDA_CPP

#include "venda.hpp"
#include <iomanip>
#include <iostream>

using namespace std;

void Venda::adicionaPedido(Pedido *p)
{
    _pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const
{
    float valor = 0;
    int iterador = 1;
    for (auto i : _pedidos)
    {
        cout << "Pedido " << iterador << endl;
        cout << i->resumo();
        valor += i->calculaTotal();
        iterador++;
    }
    cout << fixed;
    cout.precision(2);
    cout << "Relatorio de Vendas" << endl;
    cout << "Total de vendas: R$" << valor << endl;
    cout << "Total de pedidos: " << _pedidos.size();
}

Venda::~Venda()
{
    for (int i = 0, ie = _pedidos.size(); i < ie; i++)
    {
        delete _pedidos.front();
        _pedidos.pop_front();
    }
}

#endif