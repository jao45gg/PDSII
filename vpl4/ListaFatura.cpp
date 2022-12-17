#ifndef ListaFatura_cpp
#define ListaFatura_cpp

#include "ListaFatura.hpp"

ListaFatura::ListaFatura()
{

    _inicio = nullptr;
    _fim = nullptr;
    _num_elementos_inseridos = 0; // sem elementos // struct 
}

void ListaFatura::insere_fatura(Fatura *fatura)
{
    if (_num_elementos_inseridos == 0)
    {
        _inicio = fatura;
        _fim = fatura;
    }
    else
    {
        Fatura *controle_lista = _inicio->proximo;

        if (fatura->getValor() >= _inicio->getValor())
        {
            _inicio->anterior = fatura;
            fatura->proximo = _inicio;
            _inicio = fatura;
        }
        else if (fatura->getValor() < _fim->getValor())
        {
            fatura->anterior = _fim;
            _fim->proximo = fatura;
            _fim = fatura;
        }
        else if (fatura->getValor() == _fim->getValor())
        {
            fatura->anterior = _fim->anterior;
            _fim->anterior = fatura;
            fatura->anterior->proximo = fatura;
        }
        // else if (controle_lista->proximo == nullptr)
        // {
        //     _inicio->proximo = fatura;
        //     fatura->proximo = nullptr;
        //     fatura->anterior = _inicio;
        // }
        else
        {
            while (1)
            {
                if (controle_lista->getValor() <= fatura->getValor())
                {
                    fatura->proximo = controle_lista;
                    fatura->anterior = controle_lista->anterior;
                    fatura->anterior->proximo = fatura;
                    controle_lista->anterior = fatura;
                    break;
                }

                controle_lista = controle_lista->proximo;
            }
        }
    }
    _num_elementos_inseridos++;
}

Fatura *ListaFatura::proxima_fatura()
{
    Fatura *aux = _inicio;
    if (_num_elementos_inseridos == 0)
        return nullptr;
    if (_num_elementos_inseridos == 1)
    {
        _inicio = nullptr;
        _fim = nullptr;
        _num_elementos_inseridos--;
        return aux;
    }
    _inicio = _inicio->proximo;
    _inicio->anterior = nullptr;
    _num_elementos_inseridos--;
    return aux;
}

void ListaFatura::imprimir_lista()
{
    if (_num_elementos_inseridos == 0)
        return;
    Fatura *atual = _inicio;
    for (int i = 0; i < _num_elementos_inseridos; i++)
    {
        atual->imprimir_dados();
        atual = atual->proximo;
    }
}

#endif