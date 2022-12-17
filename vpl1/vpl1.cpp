#include <iostream>
#include <string>

int main()
{

    using namespace std;

    string entrada;
    cin >> entrada;

    for (char letras = 'a'; letras <= 'z'; letras++)
    {

        int contador = 0;

        for (int i = 0; i < entrada.size(); i++)
        {

            if (letras == entrada[i])
            {
                contador++;
            }
        }
        if (contador)
            cout << letras << " " << contador << endl;
        contador = 0;
    }

    return 0;
}