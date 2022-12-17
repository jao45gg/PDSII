#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

double valor_palavras(string p1)
{
    double valor = 0;
    for (int i = 0, ie = p1.size(); i < ie; i++)
    {
        valor += p1[i];
    }
    return valor;
}

bool teste_especies_com_numigual (string p1, string p2) 
{
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    if(p1 == p2)
        return false;
    return true;
}

int main()
{

    int n = 0;
    while (cin >> n)
    {
        if (!(n > 0 && n < 10000))
            break;

        vector<string> mDNA;
        int num_especies = 1;

        for (int i = 0, ie = n; i < ie; i++)
        {
            string palavras;
            cin >> palavras;
            mDNA.push_back(palavras);
        }
        for (int i = 1, ie = n; i < ie; i++)
        {
            string p1 = mDNA.at(i);
            double num_palavra = valor_palavras(p1);
            int controle = 1;

            for (int j = 0, je = i - 1; je >= j; je--)
            {
                string p2 = mDNA.at(je);
                double num_palavra_loop = valor_palavras(p2);

                if (num_palavra == num_palavra_loop)
                    controle = teste_especies_com_numigual(p1,p2);
                if (controle && je == 0)
                    num_especies++;
            }
        }
        cout << num_especies << endl;
    }

    return 0;
}