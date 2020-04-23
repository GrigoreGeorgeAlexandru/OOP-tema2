#include <iostream>
#include<math.h>
using namespace std;
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
class Complex
{
private:
    float real;
    float imaginar;

public:
Complex();
Complex(float real,float imaginar);
Complex(Complex& nr2);
~Complex();
friend istream& operator>> (istream& in, Complex&nr);
friend ostream& operator<<(ostream& out, Complex&nr);
Complex& operator=(Complex&nr);
void SetReal(float real);
float GetReal();
void SetImaginar(float imaginar);
float GetImaginar();

};

class Matrice
{protected:

Complex **v;

public:
Matrice();
Matrice(int row,int col);
Matrice(const Matrice&mat2,int row,int col);
virtual ~Matrice();
friend istream& operator>> (istream& in, Matrice&mat);
friend ostream& operator<<(ostream& out, Matrice&mat);
Matrice& operator=(Matrice&mat);
virtual void diagonala();
};

class Matrice_oarecare:public Matrice
{
private:
    int lin;
    int col;
    public:
          void SetLin(int lin);
int GetLin();
void SetCol(int col);
int GetCol();
Matrice_oarecare();
Matrice_oarecare(int row,int col);
Matrice_oarecare(const Matrice_oarecare&mat2);
~Matrice_oarecare();
friend istream& operator>> (istream& in, Matrice_oarecare&mat);
friend ostream& operator<<(ostream& out, Matrice_oarecare&mat);
 Matrice_oarecare& operator=(Matrice_oarecare&mat);
 void diagonala() override;
};

class Matrice_patratica:public Matrice
{
private:
    int dim;
    public:
             void SetDim(int dim);
int GetDim();
Matrice_patratica();
Matrice_patratica(int d);
Matrice_patratica(const Matrice_patratica&mat2);
~Matrice_patratica();
friend istream& operator>> (istream& in, Matrice_patratica&mat);
friend ostream& operator<<(ostream& out, Matrice_patratica&mat);
Matrice_patratica& operator=(Matrice_patratica&mat);
 void diagonala( ) override;
Complex determinant();
};
Matrice_oarecare* Read_N_elements(int n);
Matrice_patratica* Read_N_elements2(int n);

#endif // HEADER_H_INCLUDED
