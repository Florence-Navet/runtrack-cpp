
#include "Aquatique.hpp"
#include <iostream>



Aquatique::Aquatique(double vitesse) : vitesseNage(vitesse) {}

void Aquatique::nager() const {
    std::cout << "Je nage à " << vitesseNage << " m/s." <<std::endl;
}



double Aquatique::getVitesseNage() const {
    return vitesseNage;
}
void Aquatique::setVitesseNage(double vitesse) {
    vitesseNage = vitesse;
      }



// Créer votre colonie de pingouins en suivant les spécifications suivantes :
// ➔ Créer un vector statique et public dans votre classe Pingouin, qui
// contient tous les pingouins instanciés.
// ➔ Attention : ils doivent être retirés du vector quand ils sont détruits, en
// utilisant des shared_ptr.



