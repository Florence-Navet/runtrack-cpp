#include <iostream>
using namespace std;

void MySortString(string* tab, int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < (taille - i - 1); j ++)
        if (*(tab + j) > *(tab + j + 1)){
            string temp = *(tab + j);
            *(tab + j) = *(tab + j + 1);
            *(tab + j + 1) = temp; 
        }
    }

}

void printArray (string* tab, int taille) {
    for (int i = 0; i < taille; i++) {
        cout << *(tab + i) << " ";
    }
    cout << endl;
}


int main() {

    string mots[] = {"Nezuko", "Adeline", "Tanjiro", "Lee Min Ho", "Mashle"};

    int taille = sizeof(mots) / sizeof(mots[0]);

    cout << "Avant tri : " << endl;

    printArray(mots, taille);

    MySortString(mots, taille);

    cout << "Après tri : " << endl;

    printArray(mots, taille);



   return 0;
}

// Écrire une fonction MySortString qui prend en entrée un tableau de chaînes
// de caractères et le trie en utilisant des pointeurs. Vous devez implémenter
// votre propre algorithme de tri en utilisant des pointeurs pour accéder aux
// éléments du tableau et effectuer les échanges nécessaires. Démontrer votre
// maîtrise des algorithmes de tri.


