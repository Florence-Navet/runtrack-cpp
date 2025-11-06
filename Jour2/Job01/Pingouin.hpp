#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"

class Pingouin : public Aquatique, public Terrestre {
        private :
        double vitesseGlisse;

        public: 
        Pingouin(double vitesseNage, double vitesseMarche, double vitesseGlisse);
        Pingouin(const Pingouin& autre); //constructeur de copie

        void SePresenter() const;


        void setVitesseNage(double vitesse);
        void setVitesseMarche(double vitesse);
        void setVitesseGlisse(double vitesse);
        
};



#endif

// Reprenez votre classe Pingouin, et ajoutez-lui un Copy Constructor. done
// Ajoutez-y lui aussi une vitesse de glisse (double, m/s), privée. done
// Les vitesses doivent pouvoir être modifiées par des méthodes publiques.done