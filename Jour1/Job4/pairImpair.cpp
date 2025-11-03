#include <iostream>
using namespace std;

int main() {
    int nombre;
   cout << "Entrez un nombre\n"; 
   cin >> nombre;

   if (nombre % 2 == 0) {
    cout << nombre <<" est un nombre pair." << endl;
   }else {
    cout << nombre << " est un nombre impair." <<endl;
   }
   return 0;
}

