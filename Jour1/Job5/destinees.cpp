#include <iostream>
using namespace std;

int main() {

    int n, m, temp;
   cout << "Entrez deux entier : \n" << endl; 

   for (int i = 0; i < 2; i++) {
    cin >> n;
    cin >> m;
    cout << "avant échange n et m : "<< n<<"et" << m<< endl;
   temp = n;
   n = m;
   m = temp;

    
    cout << "après échange n et m : "<<n <<"et"<< m<<  endl;


   }
   

   return 0;
}

