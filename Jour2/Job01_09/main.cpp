#include <iostream>
#include "Pingouin.hpp"
#include <memory>
using namespace std;


int main() {
    std::cout << "Je suis le job 07 - SKILLS" << std::endl;

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



       // Partie compétences
 cout << "\n=== Gestion des compétences ===" << endl;

    pingu->ajouterCompetence("plongée", 5);
    adeline->ajouterCompetence("pêche", 8);
    thibault->ajouterCompetence("batisseur", 4);
    armelle->ajouterCompetence("chercheuse de cailloux noir", 7);

    pingu->ajouterCompetence("Faire la bouffe", 10);

    pingu->modifierCompetence("Faire la bouffe", 12);

    adeline->ajouterCompetence("chanter", 4);
 cout << "\n=== Liste des compétences ===" << endl;

    armelle ->afficherCompetences();
    pingu ->afficherCompetences();
    pingu ->supprimerCompetence("Faire la bouffe");
    pingu->afficherCompetences();

    // Relations sociales entre Pingouins
    cout <<"\n====Amitiés entre nos amis Pingouins====";

    //Creation de ses belles amitiés
    pingu->ajouterAmis(adeline);
    pingu->ajouterAmis(armelle);
    adeline->ajouterAmis(thibault);
    armelle->ajouterAmis(pingu);

    //Affichage de la liste d'amis
pingu->afficherAmis();
adeline->afficherAmis();
armelle->afficherAmis();

//ils sont fachés, ils se séparent
pingu->retirerAmis(armelle);
pingu->afficherAmis();

// Creation Journal de bord
cout <<"\n==Journal de Bord=="<<endl;

//Ajout d'évènements au journal
adeline->ajouterDonneesJournal("2025-11-03", "Premières glissade réussie à la Plateforme !!");
adeline->ajouterDonneesJournal("2025-11-04", "a reussi trou pour pêcher dans la banquise !!");
adeline->ajouterDonneesJournal("2025-11-05", "a aidé Pingu à construire son nid !!");
adeline->ajouterDonneesJournal("2025-11-06", "Elle en a ras-le-bol de l'ambiance !!");

pingu->ajouterDonneesJournal("2025-11-05", "a construit son nid avec Adeline");

// modification d'une entrées
adeline->modifierDonneesJournal("2025-11-04", "a été la première à réussir un trou pour la pêche dans la banquise");

//supprression données
adeline->supprimerDonneesJournal("2025-11-06");

//afffichage des journaux
pingu->afficherJournal();
adeline->afficherJournal();
armelle->afficherJournal();

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