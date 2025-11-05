#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Specialite { 
    IA, 
    Web, 
    Logiciel, 
    SystemeImmersif, 
    Cybersecurite, 
    NB_SPE };

string noms[] = { 
    "IA", 
    "Web", 
    "Logiciel", 
    "Système Immersif", 
    "Cybersécurité" };

int genererAleatoire(int min, int max) {
    return min + rand() % (max - min + 1);
}

void afficherSpecialite(int index, int nbEtudiants) {
    cout << noms[index] << " : " << nbEtudiants << " étudiants" << endl;
}

int main() {
    cout << "Je suis le job 17" << endl;

    srand(time(0));
    int effectifs[NB_SPE];

    for (int i = 0; i < NB_SPE; i++) {
        effectifs[i] = genererAleatoire(12, 66);
        afficherSpecialite(i, effectifs[i]);
    }

        // Affichage des spécialités
    cout << "Répartition des étudiants par spécialité :" << endl;
    for (int i = 0; i < NB_SPE; i++) {
        afficherSpecialite(i, effectifs[i]); 
    }

    return 0;
}


// Créer un programme pour une école qui gère un ensemble de spécialités.
// Déclarer une énumération Spécialité avec cinq éléments : IA, Web, Logiciel, Système Immersif Et
// Cybersécurité.
// Utiliser un tableau pour stocker les spécialités des étudiants de la promo. 

//Initialiser ce tableau avec les spécialités et  associer le nombre d’étudiants 
// de manière aléatoire (entre 12 et 66). 

// Écrire une fonction afficherSpecialite qui prend une spécialité en paramètre et
// affiche son nom ainsi que le nombre de places disponible. 
// Dans le programme principal, parcourez le tableau de spécialités et utilisez la
// fonction “afficherSpecialite” pour afficher le nom de chaque spécialité.