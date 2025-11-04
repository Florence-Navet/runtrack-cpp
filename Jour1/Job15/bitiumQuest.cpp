#include <iostream>
#include <cstdint>
using namespace std;



bool numberDeBit(uint32_t n) {
    int count = 0;
    
    while (n ) {
        count ^= (n & 1);
        n >>= 1;
    }
    return !count;
}



int main() {
 
    uint32_t nombre;
    cout << "Entrez un nombre " << endl;

    cin >> nombre;

    if (numberDeBit(nombre)) {
        cout << "Le nombre de bits à 1 dans " << nombre << " est pair." << endl;
    } else {
        cout << "Le nombre de bits à 1 dans " << nombre << " est impair." << endl;
    }



   return 0;
}




