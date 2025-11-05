#include <iostream>
using namespace std;



int calculerAuCube(int n) {
    return n *n *n;

}


int main() {

    int nombre;

    cout << "Entrez un nombre : " ;
    cin >> nombre;

    cout << "Le cube de " << nombre << " est " << calculerAuCube(nombre) << endl;


   return 0;
}




