#include <iostream>
#include "Pingouin.hpp"
#include <memory>
using namespace std;


int main() {
    std::cout << "Je suis le job 01" << std::endl;

    shared_ptr<Pingouin> p1 = make_shared<Pingouin>("Adeline",2.5, 1.8, 3.0);
    shared_ptr<Pingouin> p2 = make_shared<Pingouin>("Thibault",3.2, 1.5, 2.7);
    shared_ptr<Pingouin> p3 = make_shared<Pingouin>("Armelle",3.4, 1.7, 1.3);

    Pingouin::colonie.push_back(p1);
    Pingouin::colonie.push_back(p2);
    Pingouin::colonie.push_back(p3);

    Pingouin::afficherColonie();

    cout << "\nSuppression de Thibault";
    p2.reset();
    Pingouin::afficherColonie();

    Pingouin pingu("Pingu", 2.5, 1.8, 3.0);

    std::cout << " Oscar le pingouin se déplace : "<<std::endl;
    pingu.SePresenter();

    

   return 0;
}