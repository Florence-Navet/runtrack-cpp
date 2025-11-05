#include "Pingouin.hpp"
#include <iostream>

Pingouin::Pingouin(double vitesseNage, double vitesseMarche) : Aquatique (vitesseNage), Terrestre(vitesseMarche) {}

void Pingouin :: SePresenter() const {
  std::cout << "Je marche à " << vitesseMarche << "m/s." << std::endl;
  std::cout << "Je nage à " << vitesseNage<< "m/s." << std::endl;

}

