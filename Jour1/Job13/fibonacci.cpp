#include <iostream>
#include <cstdint>
using namespace std;


// Créer une fonction fibonacci qui calcule le
// N-ième terme de la suite de Fibonacci. Le résultat
// doit être calculé par le compilateur lors du
// traitement du code, et non lors de son exécution.
constexpr int fibonacci(int n) {
    if (n<= 1)
    return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Écrire ensuite une fonction qui prend un entier non-signé sur 32 bits en entrée
// et retourne vrai si le nombre de bits à 1 est pair et faux sinon. Testons ta
// capacité à démêler les mystères de cette suite et d’anticiper ses séquences
// numériques.
bool numberDeBit(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n & 1)
        count++;
        n >>=1;
    }
    return (count % 2 ==0);  
}



int main() {
    cout << " Les 10 premiers termes de la suite de Fibonacci sont : " << endl;

    for(int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    cout << "Verification du nombre de bit à 1 " << endl;

    uint32_t nombre;
    cout << "Entrez un nombre non signé de (0 à 294 967 295) : ";
    cin >> nombre;

    if (numberDeBit(nombre)) 
        cout << nombre << " a un nombre PAIR de bits à 1" << endl;

    else 
        cout << nombre << " a un nombre IMPAIR de bits à 1" << endl;
    



   return 0;
}




