#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Pingouin : public Aquatique, public Terrestre {
        private :
        double vitesseGlisse;
        string nom;

        public:
        double getVitesseGlisse() const;
        string getNom() const;


        public: 
        Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse);
        Pingouin(const Pingouin& autre); //constructeur de copie

        static vector<weak_ptr<Pingouin>> colonie;


    // Destructeur
    ~Pingouin();

        void SePresenter() const;

        void setVitesseNage(double vitesse);
        void setVitesseMarche(double vitesse);
        void setVitesseGlisse(double vitesse);

        static void afficherColonie();
        static void ajouterAuGroupe(shared_ptr<Pingouin> nouveau);
        static void nettoyerColonie();



        double calculerTempsParcours() const;

        static void afficherTempsPourTous();
        
};



#endif

