#ifndef AQUATIQUE_HPP
#define AQUATIQUE_HPP

class Aquatique {
     protected :
        double vitesseNage;

     public:
        Aquatique(double vitesse);
        void nager() const;
        double getVitesseNage() const;
        void setVitesseNage(double vitesse);


};

#endif