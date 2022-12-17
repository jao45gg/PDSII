#ifndef _ARRAY_CPP_
#define _ARRAY_CPP_

#include <iostream>     // std::cout, std::endl
#include <vector>       // std::vector

using namespace std;

#include "array.hpp"

void read(std::vector<int> &array) {
    int val = 0;
    do {
        cin >> val;
        array.push_back(val);
    } while(!cin.eof());
}

void print(std::vector<int> &array) {
    for(auto x : array) {
        cout << x << " ";
    }
}

void rotate(std::vector<int> &array, int r) {
    
    for (int i = 0, ie = r; i < ie; i++)
    {
   
        int numero = array[array.size() - 1];

        for (int j = (array.size() - 2); j >= 0; j--)
        {
            array[j + 1] = array[j];

        }
        array[0] = numero;

    }
}

#endif