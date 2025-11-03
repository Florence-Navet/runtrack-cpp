#include <iostream>
using namespace std;

int main() {

        int annee;
   cout << "Veuillez entree une année : \n" << endl; 
   cin >> annee; 

   if((annee % 4 == 0 && annee % 100 != 0 )|| (annee % 400 == 0)){
     cout << "L'année : " << annee<< "est bissextile"<<endl;
   } else {
     cout << "L'année : " << annee<< "n'est pas bissextile\n"<<endl;
   }

 


   return 0;
}



