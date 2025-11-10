#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Pingouin : public Aquatique, public Terrestre {
        private :
        double vitesseGlisse;
        string nom;
        static bool colonieNettoyee;

        // Map de compétences des Pingouins
        map<string, int> competences;

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

        //weak_ptr representant le cercle d'amis de mes potes pingouins
        std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;

        //journal personnel du pingouin
        std::unordered_map<std::string, std::string>journal;




        //calculs et affichage
        double calculerTempsParcours() const;
        static void afficherTempsPourTous();

        //Lieux de rencontres (statique) pour pingouins
        static vector <string>lieuxRencontre;
        //Methodes liés aux lieux
        static void ajouterLieu(const string& lieu);
        static void retirerLieu(const string& lieu);
        static void afficherLieux();

        //Methodes gestions des compétences
        void ajouterCompetence(const string& nom, int niveau);
        void modifierCompetence(const string&nom, int nouveauNiveau);
        void supprimerCompetence(const string&nom);
        void afficherCompetences();

        //Methodes de gestion des amis
        void ajouterAmis(std::shared_ptr<Pingouin>ami);
        void retirerAmis(std::shared_ptr<Pingouin>ami);
        void afficherAmis();

        //Methodes liés au journal
        void ajouterDonneesJournal(const std::string&date, const std::string& description);
        void modifierDonneesJournal(const std::string&date, const std::string& nouvelleDescription);
        void supprimerDonneesJournal(const std::string&date);
        void afficherJournal();


        //Autres
         void SePresenter() const;

        
};



#endif

