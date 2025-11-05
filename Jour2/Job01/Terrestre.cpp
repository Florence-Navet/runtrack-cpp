#include <iostream>
#include "Terrestre.hpp"

Terrestre::Terrestre(double vitesse) : vitesseMarche(vitesse) {}

void Terrestre::marcher() const {
    std::cout << "Je marche à " << vitesseMarche << "m/s/" << std::endl;
}


double Terrestre::getVitesseMarche() const {
    return vitesseMarche;
}






