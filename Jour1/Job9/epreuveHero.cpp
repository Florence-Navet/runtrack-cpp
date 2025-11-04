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

int PlusPetit(int tab[], int taille) {
     int min = tab[0];
     for (int i = 0; i < taille ; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
     }
     return min; 
}

int PlusPetitV2(int *tab, int taille) {
     int min = *tab;
     for (int i = 1; i < taille ; i++) {
        if (*(tab + i) < min) {
            min = *(tab + i);
        }
     }
     return min; 
}


int main() {

    int tableau[] = {12, 7, 5, 20, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    afficherTableau(tableau, taille);

    int min = PlusPetitV2(tableau, taille);
    cout << "Le plus petit élément du tableau est : " << min << endl;





    return 0;
}
