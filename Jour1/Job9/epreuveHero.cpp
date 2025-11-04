#include <iostream>
using namespace std;

void remplirTableau(int tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << "Entrez l'élément " << i + 1 << " : ";
        cin >> tab[i];
    }
}

void afficherTableau(int tab[], int taille) {
    cout << "Contenu du tableau : ";
    for (int i = 0; i < taille; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}



int main() {

    int tableau[] = {12, 7, 5, 20, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    afficherTableau(tableau, taille);

    return 0;
}
