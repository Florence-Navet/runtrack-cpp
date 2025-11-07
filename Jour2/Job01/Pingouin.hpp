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
        static bool colonieNettoyee;

        public:
        //contructeurs // destructeurs
        
        Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse);
        Pingouin(const Pingouin& autre); //constructeur de copie
        
        ~Pingouin();

        //getters
        double getVitesseGlisse() const;
        string getNom() const;

        //setters
        void setVitesseNage(double vitesse);
        void setVitesseMarche(double vitesse);
        void setVitesseGlisse(double vitesse);

        //colonie
        static vector<weak_ptr<Pingouin>> colonie;
        static void ajouterAuGroupe(shared_ptr<Pingouin> nouveau);
         static void nettoyerColonie();
        static void afficherColonie();
        static bool comparerTemps(const shared_ptr<Pingouin>& a, const shared_ptr<Pingouin>& b);


        //calculs et affichage
        double calculerTempsParcours() const;
        static void afficherTempsPourTous();

        //Lieux de rencontres (statique) pour pingouins
        static vector <string>lieuxRencontre;
        //Methodes liés aux lieux
        static void ajouterLieu(const string& lieu);
        static void retirerLieu(const string& lieu);
        static void afficherLieux();

        //Autres
         void SePresenter() const;

        
};



#endif

