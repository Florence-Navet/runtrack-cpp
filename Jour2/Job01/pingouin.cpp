#include "Pingouin.hpp"
#include <iostream>

Pingouin::Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {}

Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.getVitesseNage()), Terrestre(autre.getVitesseMarche()), vitesseGlisse(autre.vitesseGlisse) {}

void Pingouin :: SePresenter() const {
    std::cout << "Je marche à " << getVitesseMarche() << " m/s." << std::endl;
    std::cout << "Je nage à " << getVitesseNage() << " m/s." << std::endl;
    std::cout << "Je glisse à " << vitesseGlisse << " m/s." << std::endl;

}

void Pingouin::setVitesseNage(double vitesse) {
    Aquatique::setVitesseNage(vitesse);
}

void Pingouin::setVitesseMarche(double vitesse) {
    Terrestre::setVitesseMarche(vitesse);
}


void Pingouin::setVitesseGlisse(double vitesse) {
  vitesseGlisse = vitesse;
}




// Reprenez votre classe Pingouin, et ajoutez-lui un Copy Constructor.
// Ajoutez-y lui aussi une vitesse de glisse (double, m/s), privée.
// Les vitesses doivent pouvoir être modifiées par des méthodes publiques.
