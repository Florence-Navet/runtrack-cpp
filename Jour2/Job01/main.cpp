#include <iostream>
#include "Pingouin.hpp"
#include <memory>
using namespace std;


int main() {
    std::cout << "Je suis le job 06 - MEETUPS" << std::endl;

    // --- Création des pingouins ---
    shared_ptr<Pingouin> pingu    = make_shared<Pingouin>("Pingu",    2.5, 1.8, 3.0);
    shared_ptr<Pingouin> adeline  = make_shared<Pingouin>("Adeline",  2.5, 1.8, 3.0);
    shared_ptr<Pingouin> thibault = make_shared<Pingouin>("Thibault", 3.2, 1.5, 2.7);
    shared_ptr<Pingouin> armelle  = make_shared<Pingouin>("Armelle",  3.4, 1.7, 1.3);

    // --- Ajout à la colonie ---
    Pingouin::ajouterAuGroupe(pingu);
    Pingouin::ajouterAuGroupe(adeline);
    Pingouin::ajouterAuGroupe(thibault);
    Pingouin::ajouterAuGroupe(armelle);

    // --- Affichage de la colonie ---
    Pingouin::afficherColonie();

    // Pingouin::colonie.push_back(p1);
    // Pingouin::colonie.push_back(p2);
    // Pingouin::colonie.push_back(p3);

    // --- Suppression d’un membre ---
    cout << "\nSuppression de Thibault" << endl;
    thibault.reset();              // Thibault quitte la colonie
    Pingouin::nettoyerColonie();   // On nettoie les références mortes (ex: Thibault n'est plus snif snif)
    Pingouin::afficherColonie();   // On réaffiche la colonie de mes amis Pingouins

     // --- Présentation individuelle ---
    cout << "\n=== Présentation des membres restants ===" << endl;
    pingu->SePresenter();
    adeline->SePresenter();

    // --- Tests des lieux de rencontre ---
    cout << "\n===  Gestion des lieux de rencontre ===" << endl;
    Pingouin::afficherLieux();               // Affiche la liste initiale
    Pingouin::ajouterLieu("Ile rocailleuse"); // Ajout d’un nouveau lieu
    Pingouin::retirerLieu("banquise");       // Retrait d’un lieu
    Pingouin::afficherLieux();               // Vérifie la mise à jour


    // Pingouin pingu("Pingu", 2.5, 1.8, 3.0);

    std::cout << " Oscar le pingouin se déplace : "<<std::endl;
    // pingu.SePresenter();

    Pingouin::afficherTempsPourTous();

     cout << "\n=== Fin du Job===" << endl;

    // Pingouin::afficherColonieTrieeParTemps(); TODO a faire plus tard si j'ai envie  ah ah !!


    

   return 0;
}