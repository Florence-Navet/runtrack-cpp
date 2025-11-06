#include <iostream>
#include "Pingouin.hpp"


int main() {
    std::cout << "Je suis le job 01" << std::endl;

    Pingouin pingu(2.5, 1.8, 3.0);

    std::cout << " Oscar le pingouin se déplace : "<<std::endl;
    pingu.SePresenter();

    

   return 0;
}