#ifndef TERRESTRE_HPP
#define TERRESTRE_HPP

class Terrestre {
        protected :
        double vitesseMarche;

        public:
        Terrestre(double vitesse);
        void marcher()const;
        double getVitesseMarche() const;
};



#endif