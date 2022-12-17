#ifndef ListaFatura_hpp
#define ListaFatura_hpp

#include "Fatura.hpp"

struct ListaFatura
{

    Fatura *_inicio;
    Fatura *_fim;
    int _num_elementos_inseridos;

    ListaFatura();

    void insere_fatura(Fatura* fatura);

    Fatura* proxima_fatura();

    void imprimir_lista();
};

#endif