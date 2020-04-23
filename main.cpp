#include "header.h"
#include <iostream>
#include<math.h>
#include <stdexcept>


using namespace std;

int main()
{

    try {

        ///supraincarcari de operatori matrice oarecare
//    Matrice_oarecare matrice1;
//    cin>>matrice1;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//    cout<<matrice1;
//
//    Matrice_oarecare matrice2;
//    cin>>matrice2;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//    cout<<matrice2;
//
//matrice1=matrice2;
//cout<<matrice1;
//cout<<matrice2;
///supraincarcari de operatori matrice patratica
//    Matrice_patratica matrice1;
//    cin>>matrice1;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//    cout<<matrice1;
//
//    Matrice_patratica matrice2;
//    cin>>matrice2;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//    cout<<matrice2;
//
//matrice1=matrice2;
//cout<<matrice1;
//cout<<matrice2;
///copy constructor
//Matrice_oarecare matrice1;
//    cin>>matrice1;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//   cout<<matrice1;
//Matrice_oarecare matrice2=matrice1;
//cout<<matrice2;

///testare matrice diagonala
//Matrice_oarecare matrice1;
//    cin>>matrice1;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//   cout<<matrice1;
//matrice1.diagonala();

///afisare determinant
//Matrice_patratica matrice1;
//
//    cin>>matrice1;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//   cout<<matrice1;

///citire n elemente matrice oarecare
//Matrice_oarecare* mat;
//cout<<"numarul de matrici care vor fi citie="<<endl;
//int n;
//cin>>n;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//
//mat=Read_N_elements(n);
//
//for(int i=0;i<n;++i)
//{cout<<mat[i]<<endl;
//
//}
///citire n elemente matrice patratica
//Matrice_patratica* mat;
//cout<<"numarul de matrici care vor fi citie="<<endl;
//int n;
//cin>>n;if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");
//
//mat=Read_N_elements2(n);
//
//for(int i=0;i<n;++i)
//{cout<<mat[i]<<endl;
//
//}



}
catch (const runtime_error& e) {
        cout << e.what();
        return 1;
    }
return 0;

}
