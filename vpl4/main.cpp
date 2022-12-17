// NÃO ALTERE ESSA LINHA
#include "avaliacao.hpp"
#include "Fatura.hpp"
#include "ListaFatura.hpp"
#include <iostream>

using namespace std;

int main()
{

    char comando = 1;
    ListaFatura _lista = ListaFatura();

    while (1) // e é para finalizar o programa
    {
        cin >> comando;
        if (comando == 'e')
        {
            return 0;
        }
        
        switch (comando)
        {
        case 'f':
            int _id_;
            double _valor_;
            cin >> _id_ >> _valor_;
            _lista.insere_fatura(new Fatura(_id_, _valor_));
            break;
        case 'r':
            if (_lista._num_elementos_inseridos == 0)
                break;
            _lista.proxima_fatura()->imprimir_dados();
            break;
        case 'p':
            _lista.imprimir_lista();
            break;
        case 'a':
            avaliacao_basica();
            break;
        case 'e':
            cout << "Comando exit!";
            break;
        default:
            cout << "Comando invalido!" << endl;
            break;
        }
    }
    return 0;
}
