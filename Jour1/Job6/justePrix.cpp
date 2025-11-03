#include <iostream>
using namespace std;


  float CalculerTTC (float prixHT, float tva) {
        return prixHT * (1 + tva/100);
   }


int main() {
        
        float prixHT;
        float tva = 20;
cout << "Entrez le prix HT d'un kilo de carottes : " << endl;   
   cin >> prixHT;

   float prixTTC = CalculerTTC(prixHT, tva);

   cout << "Le prix TTC est : " << prixTTC << "euros." <<endl;
 

   return 0;
}
