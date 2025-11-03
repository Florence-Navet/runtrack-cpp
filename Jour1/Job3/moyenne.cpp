#include <iostream>
using namespace std;

//Écrire un programme en C++ qui demande à l'utilisateur de
//taper cinq entiers et qui affiche leur moyenne. Vous êtes
//limités à deux variables.

int main () {
    int n, somme = 0;

    cout << "Entrez 5 entiers : " << endl;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        somme += n;
    }

    cout << "La moyenne  est : " << (somme / 5) << endl;

    return 0;


}