#include <iostream>
using namespace std;


int* addElement (int*tab, int taille, int entier) {
    int* nouveauTab = new int[taille + 1];

    for (int i; i < taille; i++) {
        nouveauTab[i] = tab[i];
    }
    nouveauTab[taille] = entier;

    delete[] tab;

    return nouveauTab;

}

void showTable(int* tab, int taille) {
    cout << "Contenu du Tableau :";
    for (int i; i < taille; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}



int main() {
    cout << "Je suis le job 18" << endl;

    int taille = 0;
    int* tableau = new int[0];
    

    

   return 0;
}



// Dans cette quête : créer une fonction
// addElement qui prend en paramètre un
// tableau d'entiers, la taille actuelle du
// tableau et l'entier à ajouter. Cette fonction
// doit:

// ➔ allouer dynamiquement un nouveau tableau avec une taille
// augmentée de 1,
// ➔ copier les éléments de l'ancien tableau dans le nouveau,
// ➔ ajouter le nouvel entier à la fin du nouveau tableau,
// ➔ enfin, libérer la mémoire de l'ancien tableau.
//---------------------------------------------------

// Créer une fonction showTable qui prend en paramètre un tableau d'entiers et
// sa taille, et qui affiche tous les éléments du tableau.

// Créer un tableau d'entiers vide avec une capacité
// initiale de 5 éléments. Ajoutez plusieurs entiers au
// tableau à l'aide de la fonction addElement, puis
// affichez le tableau à l'aide de la fonction showTable.