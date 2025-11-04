#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n<= 1)
    return n;
    return fibonacci(n-1) + fibonacci(n-2);
}



int main() {
    cout << " Les 10 premiers termes de la suite de Fibonacci sont : " << endl;

    for(int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;


   return 0;
}


// Créer une fonction fibonacci qui calcule le
// N-ième terme de la suite de Fibonacci. Le résultat
// doit être calculé par le compilateur lors du
// traitement du code, et non lors de son exécution.