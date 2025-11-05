#include <iostream>
#include "Aquatique.hpp"


Aquatique::Aquatique(double vitesse) : vitesseNage(vitesse) {}

void Aquatique::nager() const {
    std::cout << "Je nage à " << vitesseNage << " m/s." <<std::endl;
}


double Aquatique::getVitesseNage() const {
    return vitesseNage;
}


\



