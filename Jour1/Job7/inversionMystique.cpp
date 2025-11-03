#include <iostream>
using namespace std;

int main() {

        string nombre, inverse = "";
   cout << "Veuillez saisir un nombre au moins deux chiffres : \n" << endl; 
   cin >> nombre; 

   for (int i = nombre.length() -1 ; i >=0; i--) {
        inverse += nombre [i];
   }

   cout << "Le nombre inverse est :  "<< inverse << endl;


   return 0;
}



