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
    std::cout << "Je m'appelle " << getNom() << " !" << std::endl;
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
    bool comparator (int a, int b) {
        return a > b;
    }

void Pingouin::ajouterAuGroupe(shared_ptr<Pingouin> nouveauPingouin) {
    colonie.push_back(nouveauPingouin); // ajout ici du nouveau pingouin
    
    //convertir weak_ptr en shared_ptr
    std::vector<shared_ptr<Pingouin>> pingouinsActifs;
    for (std::vector<std::weak_ptr<Pingouin>>::iterator it = colonie.begin(); it !=colonie.end(); ++it)  {
        std::shared_ptr<Pingouin>pingouin = it ->lock(); //transforme weak en shared
        if (pingouin) {
            pingouinsActifs.push_back(pingouin);
        }
    } 

    //trier pingouins par temps de parcours croissants
    std::sort(pingouinsActifs.begin(), pingouinsActifs.end(),
    [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>&b) {
        return a->calculerTempsParcours() < b->calculerTempsParcours();
    });

    //reconstruction de la colonie
    colonie.clear(); //on vide la coloine

    //on remplit la colonie avec les pingouins triés en les convertissants en weak_ptr
    for (std::vector<std::shared_ptr<Pingouin>>::iterator it = pingouinsActifs.begin(); it != pingouinsActifs.end(); ++it) {
        colonie.push_back(*it);
    }

    std::cout << "\n Le pingouin " << nouveauPingouin->getNom()
                << " a été ajouté et la colonie a été triée par temps de parcours." << std::endl;

 std::cout << "\nColonie triée par temps de parcours :\n";
    for (std::vector<std::shared_ptr<Pingouin>>::iterator it = pingouinsActifs.begin(); it != pingouinsActifs.end(); ++it) {
        std::shared_ptr<Pingouin> pingouin = *it;
        std::cout << "• " << pingouin->getNom()
                  << " → " << pingouin->calculerTempsParcours() << " s" << std::endl;
    }

    
    
}

void Pingouin::nettoyerColonie() {
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin>& wp) { return wp.expired(); }),
        colonie.end());
}

// void Pingouin::ColonieParTempsDeParcours() {
//     std::cout << "\nColonie triée par temps de parcours :\n";
// for (std::vector<std::shared_ptr<Pingouin>>::iterator it = pingouinsActifs.begin(); it != pingouinsActifs.end(); ++it) {
//     std::shared_ptr<Pingouin> pingouin = *it;
//     std::cout << "• " << pingouin->getNom()
//               << " → " << pingouin->calculerTempsParcours() << " s" << std::endl;
// }

// }



void Pingouin::afficherColonie() {
    cout << "\nColonie actuelle :" << endl;
    for (std::weak_ptr<Pingouin> &pingouinFaible : colonie) {
        std::shared_ptr<Pingouin> pingouin = pingouinFaible.lock();
        if (pingouin) {  
            pingouin->SePresenter();
        }
    }
}
double Pingouin::getVitesseGlisse() const {
    return vitesseGlisse;
}

string Pingouin::getNom() const {
    return nom;
}



double Pingouin::calculerTempsParcours() const {

    const double distanceGlisse = 15.0;
    const double distancePlat1 = 20.0;
    const double distanceNage = 50.0;
    const double distancePlat2 = 15.0;


    double tempsGlisse = distanceGlisse / vitesseGlisse;
    double tempsPlat = (distancePlat1 + distancePlat2) / getVitesseMarche();
    double tempsNage = distanceNage / getVitesseNage();

    double tempsTotal = tempsGlisse + tempsPlat + tempsNage;
    return tempsTotal;
}

//Methode affichant temps parcours pour les pingouins
void Pingouin::afficherTempsPourTous() {
    cout << "\n Temps de parcours pour chaque pingouin de la colonie : " << endl;

    for (std::weak_ptr<Pingouin> &pingouinFaible : colonie) {
        std::shared_ptr<Pingouin> pingouin = pingouinFaible.lock();

        if (pingouin) {
            double temps = pingouin ->calculerTempsParcours();
            cout << pingouin ->getVitesseMarche() << " m/s à la marche, "
            << pingouin ->getVitesseNage() << " m/s à la nage,"
            << "glisse à " << pingouin -> getVitesseGlisse() << " m/s -> ";
            cout << "temps total : " << temps << " secondes (" << pingouin->getNom() << ")" << endl;
        }
    }
}





