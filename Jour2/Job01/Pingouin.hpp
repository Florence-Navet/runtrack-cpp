#ifndef PINGOUIN_HPP
#define PINGOUIN_HPP

#include "Aquatique.hpp"
#include "Terrestre.hpp"

class Pingouin : public Aquatique, public Terrestre {
        public: 
        Pingouin(double vitesseNage, double vitesseMarche);
        void SePresenter() const;
};



#endif