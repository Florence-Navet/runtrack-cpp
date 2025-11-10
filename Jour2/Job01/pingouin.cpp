#include "Pingouin.hpp"
#include <iostream>
#include <algorithm>
#include <string>   
#include <map>
using namespace std;


//initialisation de ma colonie
vector<weak_ptr<Pingouin>> Pingouin::colonie;

//initialisation de ma liste statique de lieux
vector<string> Pingouin::lieuxRencontre = {"glacier", "banquise", "océan", "montagne du caillou blanc"};

//initialisation de ma variable bool
bool Pingouin::colonieNettoyee = false;

// Constructeurs / destruteurs
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
    // nettoyerColonie();
    if (!colonieNettoyee) {
        nettoyerColonie();
        colonieNettoyee = true;
    }

    //------------------METHODES DE COLONIES-------------------------------------
    // Nettoyer les références 
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin> &wp) { return wp.expired(); }),
        colonie.end());
}


void Pingouin::ajouterAuGroupe(shared_ptr<Pingouin> nouveauPingouin) {
    colonie.push_back(nouveauPingouin); // ajout ici du nouveau pingouin
    
    //convertir weak_ptr en shared_ptr
    vector<shared_ptr<Pingouin>> pingouinsActifs;
    for (vector<std::weak_ptr<Pingouin>>::iterator it = colonie.begin(); it !=colonie.end(); ++it)  {
        shared_ptr<Pingouin>pingouin = it ->lock(); //transforme weak en shared
        if (pingouin) {
            pingouinsActifs.push_back(pingouin);
        }
    } 


    // Tri via la fonction comparerTemps - booleen 
    // pingouin plus rapide avec plus lent : return true si  a arrive avant b dans le
    // booleen
    sort(pingouinsActifs.begin(), pingouinsActifs.end(), Pingouin::comparerTemps);

    //reconstruction de la colonie
    colonie.clear(); //on vide la colonie


    //on remplit la colonie avec les pingouins triés en les convertissants en weak_ptr
    for (vector<shared_ptr<Pingouin>>::iterator it = pingouinsActifs.begin(); it != pingouinsActifs.end(); ++it) {
        colonie.push_back(*it);
    }

cout << "\n Le pingouin " << nouveauPingouin->getNom()
                << " a été ajouté et la colonie a été triée par temps de parcours." << endl;

 cout << "\nColonie triée par temps de parcours :\n";
    for (std::vector<shared_ptr<Pingouin>>::iterator it = pingouinsActifs.begin(); it != pingouinsActifs.end(); ++it) {
    shared_ptr<Pingouin> pingouin = *it;
    cout << "• " << pingouin->getNom()
                  << " → " << pingouin->calculerTempsParcours() << " s" << endl;
    }

    
    
}

bool Pingouin::comparerTemps(const shared_ptr<Pingouin>& a, const shared_ptr<Pingouin>& b) {
    return a->calculerTempsParcours() < b->calculerTempsParcours();
}


void Pingouin::nettoyerColonie() {
    colonie.erase(
        remove_if(colonie.begin(), colonie.end(),
                  [](weak_ptr<Pingouin>& wp) { return wp.expired(); }),
        colonie.end());
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



// -- METHODES LIEES AU LIEUX --

void Pingouin::ajouterLieu(const string& lieu) {
    // check si le lieu n'est pas deja existant
    if (find(lieuxRencontre.begin(), lieuxRencontre.end(), lieu) == lieuxRencontre.end()) {
        lieuxRencontre.push_back(lieu);
        cout << " Nouveau lieu ajouté : " << lieu << endl;
    } else {
        cout << "Le lieu " << lieu << " existe déjà." <<endl;
    }
}

void Pingouin::retirerLieu(const string& lieu) {
    //creation d'un iterateur sur le vector <string>
    std::vector<std::string>::iterator it = std::remove(lieuxRencontre.begin(), lieuxRencontre.end(), lieu);

    if (it != lieuxRencontre.end()) {
        lieuxRencontre.erase(it, lieuxRencontre.end());
        std::cout << "Lieu retiré : "<< lieu << std::endl;
    } else  {

    std:: cout << "Aucun lieu trouvé ne correspond à "<< lieu << " ." << std::endl;
}


}

void Pingouin::afficherLieux() {
    cout << "\n Lieux de rencontre de nos amis Pingouins :" << endl;
    for(vector <string>::iterator it = lieuxRencontre.begin(); it != lieuxRencontre.end(); ++it) {
        cout <<  " - " << *it << endl;
    }
}


// -- AUTRES METHODES --


void Pingouin :: SePresenter() const {
    std::cout << "Je m'appelle " << getNom() << " !" << std::endl;
    std::cout << "Je marche à " << getVitesseMarche() << " m/s." << std::endl;
    std::cout << "Je nage à " << getVitesseNage() << " m/s." << std::endl;
    std::cout << "Je glisse à " << vitesseGlisse << " m/s." << std::endl;

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

// --GESTION DES COMPETENCES--
void Pingouin::ajouterCompetence(const string& nom, int niveau) {
    // Vérifie si la compétence existe déjà
    if (competences.find(nom) == competences.end()) {
        competences[nom] = niveau;
        cout << " [ "<<this ->nom <<" ] "<< "- Nouvelle compétence ajoutée : " << nom << " (niveau " << niveau << ")" << endl;
    } else {
        cout << " [ "<<this ->nom <<" ] "<< "- La compétence " << nom << " existe déjà. Utilisez modifierCompetence()." << endl;
    }
}

void Pingouin::modifierCompetence(const string&nom, int nouveauNiveau)
{
    map<string, int>::iterator it = competences.find(nom);
    if(it != competences.end()) {
        it->second = nouveauNiveau;
        cout << "Compétence " << nom << " mise à jour au niveau " << nouveauNiveau << endl;
                cout <<"vous avez levUp !!" << endl;
    } else {
        cout << "Aucune compétence particulière associée au nom. " << nom << endl;
    }
}
void Pingouin::supprimerCompetence(const string&nom)
{
        map<string, int>::iterator it = competences.find(nom);
        if (it != competences.end()) {
            competences.erase(it);
            cout << "Compétence " <<nom << " supprimée." <<endl;
        } else 
        {
            cout << " Impossible de supprimer : compétence " << nom  <<" introuvable ou inexistance" << endl;
        }
}

void Pingouin::afficherCompetences() 
{
    cout << "\nCompétences de " << nom << " : " << endl;
    if (competences.empty())
    {
    cout << "  Aucune compétence enregistrée. T'es pas bon !!! " << endl;

    } else 
    {
        for (map <string, int> ::const_iterator it = competences.begin(); it != competences.end(); ++it)
        {
            cout << " - " << it->first << " : niveau " << it->second << endl;
        }
    }
}




// ====================
// GETTERS & SETTERS
// ====================

// --- Vitesses ---
void Pingouin::setVitesseNage(double vitesse) {
    Aquatique::setVitesseNage(vitesse);
}

void Pingouin::setVitesseMarche(double vitesse) {
    Terrestre::setVitesseMarche(vitesse);
}

void Pingouin::setVitesseGlisse(double vitesse) {
    vitesseGlisse = vitesse;
}

double Pingouin::getVitesseGlisse() const {
    return vitesseGlisse;
}

// --- Identité ---
string Pingouin::getNom() const {
    return nom;
}



