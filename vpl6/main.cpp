#include <iostream>







// PROGRAMA NAO TERMINADO 







// Bibliotecas sugeridas para resolver o problema:
//
// MAP
#include <map>
// VECTOR
#include <vector>
// PAIR
#include <utility>

using namespace std;

vector<int> achar_senha(pair<vector<char>, vector<char> > *_Letras_,vector<pair<int, int> > *_Numeros_)
{
    vector<pair<int, int> > assosiacao;
    vector<pair<int, int> > assosiacao1;
    vector<int> senha;
    for (int i = 0; i < 5; i++)
    {
        char letra = _Letras_->first.at(i);
        switch (letra)
        {
        case 'A':
            assosiacao.push_back(_Numeros_->at(0));
            break;
        case 'B':
            assosiacao.push_back(_Numeros_->at(1));
            break;
        case 'C':
            assosiacao.push_back(_Numeros_->at(2));
            break;
        case 'D':
            assosiacao.push_back(_Numeros_->at(3));
            break;
        case 'E':
            assosiacao.push_back(_Numeros_->at(4));
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        char letra = _Letras_->second.at(i);
        switch (letra)
        {
        case 'A':
            assosiacao1.push_back(_Numeros_->at(0));
            break;
        case 'B':
            assosiacao1.push_back(_Numeros_->at(1));
            break;
        case 'C':
            assosiacao1.push_back(_Numeros_->at(2));
            break;
        case 'D':
            assosiacao1.push_back(_Numeros_->at(3));
            break;
        case 'E':
            assosiacao1.push_back(_Numeros_->at(4));
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (assosiacao.at(i).first == assosiacao1.at(i).first)
        {
            senha.push_back(assosiacao.at(i).first);
        }
        else if (assosiacao.at(i).first == assosiacao1.at(i).second)
        {
            senha.push_back(assosiacao.at(i).first);
        }
        else if (assosiacao.at(i).second == assosiacao1.at(i).first)
        {
            senha.push_back(assosiacao.at(i).first);
        }
        else if (assosiacao.at(i).second == assosiacao1.at(i).second)
        {
            senha.push_back(assosiacao.at(i).first);
        }
    }
    return senha;
}

void juntar_letras(pair<vector<char>, vector<char> > *_Letras_, 
        vector<char> *_letra1_, vector<char> *_letra2_)
{
    *_Letras_ = make_pair(*_letra1_, *_letra2_);
}

void juntar_letras1(pair<pair<vector<char>, vector<char> >, vector<char> > *_Letras_, 
        vector<char> *_letra1_, vector<char> *_letra2_, vector<char> *_letra3_)
{
    *_Letras_ = make_pair(make_pair(*_letra1_, *_letra2_), *_letra3_);
}

void ler_letras(vector<char> *_letra1_, vector<char> *_letra2_, int n)
{
    if(n == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            char letra;
            cin >> letra;
            _letra1_->push_back(letra);
        }
    }
    if(n == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            char letra;
            cin >> letra;
            _letra2_->push_back(letra);
        }
    }
}

void ler_letras1(vector<char> *_letra1_, vector<char> *_letra2_, vector<char> *_letra3_, int n)
{
    if(n == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            char letra;
            cin >> letra;
            _letra1_->push_back(letra);
        }
    }
    if(n == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            char letra;
            cin >> letra;
            _letra2_->push_back(letra);
        }
    }
    if(n == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            char letra;
            cin >> letra;
            _letra3_->push_back(letra);
        }
    }
}

void ler_numeros(vector<pair<int, int> > *_Numeros)
{
    for (int i = 0; i < 5; i++)
    {
        int num = 0, num1 = 0;
        cin >> num >> num1;
        _Numeros->push_back(make_pair(num, num1));
    }
}

int main()
{
    int N = 0;
    cin >> N;
    vector<pair<int, int> > *Numeros;
    if(N == 2) 
    {
        vector<char> *letra1, *letra2;
        pair<vector<char>, vector<char> > *Letras;
        for (int i = 0; i < N; i++)
        {
            ler_numeros(Numeros);
        }
        for (int i = 0; i < N; i++)
        {
            ler_letras(letra1, letra2, N-i);
        }
        juntar_letras(Letras, letra1, letra2);
        vector <int> senha = achar_senha(Letras, Numeros);
        for (int i = 0; i < senha.size(); i++)
        {
            cout << senha.at(i) << " ";
        }
        
    }
    if(N == 3)
    {
        vector<char> *letra1, *letra2, *letra3;
        pair<pair<vector<char>, vector<char> >, vector<char> > *Letras;
        for (int i = 0; i < N; i++)
        {
            ler_numeros(Numeros);
        }
        for (int i = 0; i < N; i++)
        {
            ler_letras1(letra1, letra2, letra3, N-i);
        }
        juntar_letras1(Letras, letra1, letra2, letra3); 
        //vector <int> senha = achar_senha(Letras, Numeros);
        //for (int i = 0; i < senha.size(); i++)
        //{
        //    cout << senha.at(i) << " ";
        //}   
    }

    

    return 0;
}