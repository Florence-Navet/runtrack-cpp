#include <iostream>


using namespace std;

void echangeEntier(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Après échange dans la fonction echangeEntier : a = " << a << ", b = " << b << endl;
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Après échange dans la fonction swapValues: a = " << a << ", b = " << b << endl;
}







