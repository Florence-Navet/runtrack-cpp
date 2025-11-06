#include "Pingouin.hpp"
#include <iostream>
#include <algorithm>
#include <string>   

vector<weak_ptr<Pingouin>> Pingouin::colonie;

Pingouin::Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
    : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom),vitesseGlisse(vitesseGlisse) 
    {
      cout << nom << " vient de rejoindre la colonie." << endl;
    }


Pingouin::Pingouin(const Pingouin& autre)
    : Aquatique(autre.getVitesseNage()), 
    Terrestre(autre.getVitesseMarche()),
    nom(autre.nom + "_copie"),
    vitesseGlisse(autre.vitesseGlisse)
    {
      cout << "Copie du pingouin " << autre.nom << " → " << nom << endl;
    }

    //  Destructeur
Pingouin::~Pingouin() {
    cout << " Le pingouin " << nom << " a quitté la colonie." << endl;

    // Nettoyer les références 
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin> &wp) { return wp.expired(); }),
        colonie.end());
}

void Pingouin :: SePresenter() const {
    std::cout << "Je m'appelle " << nom << " !" << std::endl;
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


void Pingouin::afficherColonie() {
    cout << "\nColonie actuelle :" << endl;
    for (std::weak_ptr<Pingouin> &pingouinFaible : colonie) {
        std::shared_ptr<Pingouin> pingouin = pingouinFaible.lock();
        if (pingouin) {  
            pingouin->SePresenter();
        }
    }
}


double Pingouin::calculerTempsParcours()const {
    const double distanceGlisse = 15.0;
    const double distancePlatNr1 = 20.0;
    const double distancePlatNr2 = 15.0;
    const double distanceNage = 20.0;

    //temps = distance / vitesse
    double tempsGlisse = distanceGlisse / vitesseGlisse;
    double tempsPlat = (distancePlatNr1 + distancePlatNr2) / getVitesseMarche;
    double tempsNage = distanceNage / getVitesseNage();

    double tempsTotal = tempsGlisse + tempsPlat + tempsNage
    return tempsTotal


}




