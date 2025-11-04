#include <iostream>
using namespace std;
#include "../Job5/destinees.cpp"




int main() {

    int n, m;
   cout << "Entrez deux entier : \n" << endl; 


    cin >> n;
    cin >> m;

    cout << "Avant échange : n = " << n << ", m = " << m << endl;
    echangeEntier(n, m);
    cout << "Après appel de la fonction : n = " << n << ", m = " << m << endl;

        cout << "Avant échange : n = " << n << ", m = " << m << endl;
    swapValues(n, m);
    cout << "Après appel de la fonction : n = " << n << ", m = " << m << endl;


   return 0;
}


// Écrire une fonction swapValues qui, tel un défi d’adresse, teste votre habilité à
// échanger avec maîtrise les valeurs de deux entiers en utilisant les références.
// Dans cette épreuve, vous êtes appelé à démontrer votre dextérité et votre
// efficacité. Vous ne devez pas utiliser de pointeurs pour cet exercice.