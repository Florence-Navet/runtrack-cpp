#include <iostream>
#include <cstdint>
using namespace std;


// Écrire une fonction doubleArray qui prend un tableau d'entiers et sa taille en
// entrée, qui double chaque élément du tableau en utilisant des pointeurs pour
// accéder aux éléments du tableau, et renvoie la somme de tous les éléments
// doublés.
int  doubleArray(int* tab, int taille) {
    int somme = 0;

    for (int i = 0; i < taille; i++) {
        *(tab+i) *= 2;  // on commence par doubler tous les éléments
        somme += *(tab +i);
    }
    return somme;

}

// Ensuite, écrivez une fonction printArray qui prend un tableau d'entiers et sa
// taille en entrée, et affiche les éléments du tableau après les avoir doublés.
void printArray(int*tab, int taille) {
    for (int i = 0 ; i < taille; i++) {
        cout << *(tab +i) << " ";
    }
    cout << endl;

}



int main() {

   const int taille = 5;
   int tableau [taille];
  cout << "Entrez" << taille << " nombres entier : " << endl;   
 for (int i = 0 ; i < taille ; i++) {
    cout << "Element " << i + 1 << " : ";
    cin >> *(tableau + i);
 }

cout << "\nAvant doublement : ";
printArray(tableau, taille);

int somme = doubleArray(tableau, taille);
cout <<"Après doublement :";
printArray(tableau, taille);


cout << "Somme des éléments doublés = " << somme << endl;



   return 0;
}




