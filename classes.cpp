#include "header.h"
Complex::Complex(){
this->real=0;
this->imaginar=0;


}
Complex::Complex(float real,float imaginar){

this->real=real;
this->imaginar=imaginar;


}
Complex::Complex(Complex& nr2){

this->real=nr2.GetReal();
this->imaginar=nr2.GetImaginar();


}
Complex::~Complex(){





}
istream& operator>> (istream& in, Complex&nr)
{

 float nr1;
    cout<<"partea reala a primului element este:\n";

    in>>nr1; if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
    nr.SetReal(nr1);
 cout<<"partea imaginara a primului element este:\n";

    in>>nr1;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
        nr.SetImaginar(nr1);
    return in;


}
ostream& operator<<(ostream& out, Complex&nr){
out<<nr.GetReal()<<"+"<<nr.GetImaginar()<<"i\n";
return out;
}
Complex& Complex::operator=(Complex&nr){

                 this->SetReal(nr.GetReal());
  this->SetImaginar(nr.GetImaginar()); return *this;


}

Matrice::Matrice(){

  v = new Complex*;
           v[0]=new Complex;




}
Matrice::Matrice(int row,int col){
   v = new Complex*[row];
           for(int i = 0; i < row; ++i)
                v[i] = new Complex[col];



}
Matrice::Matrice(const Matrice&mat2,int row=0,int col=0){



this->v=new Complex*[row];
           for(int i = 0; i < row; ++i)
               {
                this->v[i] = new Complex[col];
                for(int j=0;j<col;++j)
                   {


                   this->v[i][j].SetReal(mat2.v[i][j].GetReal());
  this->v[i][j].SetImaginar(mat2.v[i][j].GetImaginar());}
               }



}



 Matrice:: ~Matrice(){

//cout<<"destructor base";
}

void Matrice::diagonala(){}
Matrice_oarecare::Matrice_oarecare():Matrice(){

lin=1;
col=1;





}


Matrice_oarecare::Matrice_oarecare(int row,int col):Matrice(row,col)
{
this->lin=row;
this->col=col;
}


Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare&mat2):Matrice(mat2,mat2.lin,mat2.col){

this->lin=mat2.lin;
this->col=mat2.col;


}


Matrice_oarecare::~Matrice_oarecare(){
for(int i = 0; i <lin ; ++i) {

               delete[] v[i];
    }

delete[] v;

//cout<<"destructor derived";
this->SetCol(0);
this->SetLin(0);

}


Matrice_patratica::Matrice_patratica():Matrice(){
dim=1;






}


Matrice_patratica::Matrice_patratica(int d):Matrice(d,d)
{
this->dim=d;
}


Matrice_patratica::Matrice_patratica(const Matrice_patratica&mat2):Matrice(mat2,mat2.dim,mat2.dim){

this->dim=mat2.dim;

}


Matrice_patratica::~Matrice_patratica(){

for(int i = 0; i <dim ; ++i) {

               delete[] v[i];
    }

delete[] v;

this->SetDim(0);


}

void Complex::SetReal(float real){this->real=real;}
float Complex::GetReal(){ return real;}

void Complex::SetImaginar(float imaginar){this->imaginar=imaginar;}
float Complex::GetImaginar(){ return imaginar;}



istream& operator>> (istream& in, Matrice&mat)
{






    float nr;
    cout<<"partea reala a primului element este:\n";
    in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
    mat.v[0][0].SetReal(nr);
 cout<<"partea imaginara a primului element este:\n";
    in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
        mat.v[0][0].SetImaginar(nr);
    return in;
}

 ostream& operator<<(ostream& out, Matrice&mat)
{out<<"matricea este:\n";
   out<<mat.v[0][0].GetReal()<<"+"<<mat.v[0][0].GetImaginar()<<"i\n";
return out;
}
Matrice& Matrice::operator=(Matrice&mat)
  {

                   this->v[0][0].SetReal(mat.v[0][0].GetReal());
  this->v[0][0].SetImaginar(mat.v[0][0].GetImaginar()); return *this;}

void Matrice_oarecare::SetCol(int col){this->col=col;}
int Matrice_oarecare::GetCol(){ return col;}

void Matrice_oarecare::SetLin(int lin){this->lin=lin;}
int Matrice_oarecare::GetLin(){ return lin;}
  void Matrice_patratica::SetDim(int dim){this->dim=dim;}
int Matrice_patratica::GetDim(){ return dim;}


  istream& operator>> (istream& in, Matrice_oarecare&mat)
{for(int i = 0; i <mat.GetLin() ; ++i) {

               delete[] mat.v[i];
    }

delete[] mat.v;
mat.SetCol(0);
mat.SetLin(0);


    int nr1;
cout<<"numarul de linii ale matricei este:\n";
in>>nr1;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.SetLin(nr1);
cout<<"numarul de coloane ale matricei este:\n";

in>>nr1;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.SetCol(nr1);

 mat.v = new Complex*[mat.GetLin()];
           for(int i = 0; i < mat.GetLin(); ++i)
                mat.v[i] = new Complex[mat.GetCol()];
    for(int i=0;i<mat.GetLin();++i)
for(int j=0;j<mat.GetCol();++j)
{float nr;
cout<<"partea reala a elementului de pe randul "<<i+1<<" ,coloana "<<j+1<<" este:\n";
in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.v[i][j].SetReal(nr);
cout<<"partea imaginara a elementului de pe randul "<<i+1<<" ,coloana "<<j+1<<" este:\n";
in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.v[i][j].SetImaginar(nr);

}
return in;
}

 ostream& operator<<(ostream& out, Matrice_oarecare&mat)
{out<<"matricea este:\n";
for(int i=0;i<mat.GetLin();++i)
{for(int j=0;j<mat.GetCol();++j)
   out<<mat.v[i][j].GetReal()<<"+"<<mat.v[i][j].GetImaginar()<<"i ";
out<<endl;
}
return out;
}
Matrice_oarecare& Matrice_oarecare::operator=(Matrice_oarecare&mat)
  {for(int i = 0; i <this->GetLin() ; ++i) {
//cout<<this->v[i][j].GetReal()<<"+"<<this->v[i][j].GetImaginar()<<"i ";
               delete[] this->v[i];
    }

delete[] this->v;


this->SetCol(0);
this->SetLin(0);




 this->v = new Complex*[mat.GetLin()];
           for(int i = 0; i < mat.GetLin(); ++i)
                this->v[i] = new Complex[mat.GetCol()];



this->SetCol(mat.GetCol());
this->SetLin(mat.GetLin());

      for(int i=0;i<mat.GetLin();++i)
for(int j=0;j<mat.GetCol();++j)
{


                   this->v[i][j].SetReal(mat.v[i][j].GetReal());
  this->v[i][j].SetImaginar(mat.v[i][j].GetImaginar());}

  return *this;

  }
   istream& operator>> (istream& in, Matrice_patratica&mat)
{
    for(int i = 0; i <mat.GetDim() ; ++i) {

               delete[] mat.v[i];
    }

delete[] mat.v;

mat.SetDim(0);





    int nr1;
cout<<"numarul de linii/coloane ale matricei este:\n";
in>>nr1;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.SetDim(nr1);

 mat.v = new Complex*[mat.GetDim()];
           for(int i = 0; i < mat.GetDim(); ++i)
                mat.v[i] = new Complex[mat.GetDim()];








    for(int i=0;i<mat.GetDim();++i)
for(int j=0;j<mat.GetDim();++j)
{float nr;
cout<<"partea reala a elementului de pe randul "<<i+1<<" ,coloana "<<j+1<<" este:\n";
in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.v[i][j].SetReal(nr);
cout<<"partea imaginara a elementului de pe randul "<<i+1<<" ,coloana "<<j+1<<" este:\n";
in>>nr;if (in.fail()) throw runtime_error("Nu ati introdus un numar\n");
mat.v[i][j].SetImaginar(nr);


}
return in;
}

 ostream& operator<<(ostream& out, Matrice_patratica&mat)
{out<<"matricea este:\n";
for(int i=0;i<mat.GetDim();++i)
{for(int j=0;j<mat.GetDim();++j)
   out<<mat.v[i][j].GetReal()<<"+"<<mat.v[i][j].GetImaginar()<<"i ";
out<<endl;
}
out<<"determinantul matricei este:";
out<<mat.determinant().GetReal()<<"+"<<mat.determinant().GetImaginar()<<"i ";
out<<endl;


return out;
}
Matrice_patratica& Matrice_patratica::operator=(Matrice_patratica&mat)
  {

    for(int i = 0; i <this->GetDim() ; ++i) {

               delete[] this->v[i];
    }

delete[] this->v;

this->SetDim(0);




      this->v = new Complex*[mat.GetDim()];
           for(int i = 0; i < mat.GetDim(); ++i)
                this->v[i] = new Complex[mat.GetDim()];


this->SetDim(mat.GetDim());


      for(int i=0;i<mat.GetDim();++i)
for(int j=0;j<mat.GetDim();++j)
{


                   this->v[i][j].SetReal(mat.v[i][j].GetReal());
  this->v[i][j].SetImaginar(mat.v[i][j].GetImaginar());}

  return *this;

  }


  void Matrice_oarecare::diagonala ( )
  {
  int d1=1;
  int d2=1;
  for (int i=0;i<this->GetLin();++i)
    {
        for (int j=0;j<this->GetCol();++j)
  if(i>j &&(this->v[i][j].GetReal()!=0 ||this->v[i][j].GetImaginar()!=0))
    {d1=0;
    break;

    }
    if(d1==0)
        break;
    }

 for (int i=0;i<this->GetLin();++i)
    {
        for (int j=0;j<this->GetCol();++j)
  if(i<j &&(this->v[i][j].GetReal()!=0 ||this->v[i][j].GetImaginar()!=0))
    {d2=0;
    break;

    }
    if(d2==0)
        break;
    }
  if(d1==1 && d2==1)
    cout<<"matricea este diagonala\n";
  else if(d1==1 || d2==1)
    cout<<"matricea este triunghiulara,dar nu diagonala\n";
  else
    cout<<"matricea nu este triunghiulara\n";

  }

  void Matrice_patratica::diagonala ( )
  {
  int d1=1;
  int d2=1;
  for (int i=0;i<this->GetDim();++i)
    {
        for (int j=0;j<this->GetDim();++j)
  if(i>j &&(this->v[i][j].GetReal()!=0 ||this->v[i][j].GetImaginar()!=0))
    {d1=0;
    break;

    }
    if(d1==0)
        break;
    }

 for (int i=0;i<this->GetDim();++i)
    {
        for (int j=0;j<this->GetDim();++j)
  if(i<j &&(this->v[i][j].GetReal()!=0 ||this->v[i][j].GetImaginar()!=0))
    {d2=0;
    break;

    }
    if(d2==0)
        break;
    }
  if(d1==1 && d2==1)
    cout<<"matricea este diagonala\n";
  else if(d1==1 || d2==1)
    cout<<"matricea este triunghiulara,dar nu diagonala\n";
  else
    cout<<"matricea nu este triunghiulara\n";

  }

Complex Matrice_patratica::determinant(){

   Complex nr;
   nr.SetReal(0);
   nr.SetImaginar(0);
   Matrice_patratica mat2(this->GetDim());

   if (this->GetDim()== 1)
   {
      nr.SetReal(this->v[0][0].GetReal());
   nr.SetImaginar(this->v[0][0].GetImaginar());
   return nr;
   }
   else if (this->GetDim()== 2)
{


          nr.SetReal( (this->v[0][0].GetReal()*this->v[1][1].GetReal()-this->v[0][0].GetImaginar()*this->v[1][1].GetImaginar())-

                (this->v[0][1].GetReal()*
                 (this->v[1][0].GetReal())
                 - this->v[0][1].GetImaginar()*(this->v[1][0].GetImaginar())));
            nr.SetImaginar((this->v[0][0].GetReal()*this->v[1][1].GetImaginar()-this->v[0][0].GetImaginar()*this->v[1][1].GetReal())-
                           (this->v[0][1].GetReal()*this->v[1][0].GetImaginar()-this->v[0][1].GetImaginar()*this->v[1][0].GetReal())
                           );

          return nr;}
   else {


      for (int x = 0; x < this->GetDim(); x++) {
            int subi = 0;
            for (int i = 1; i < this->GetDim(); i++) {
               int subj = 0;
               for (int j = 0; j < this->GetDim(); j++) {

                if (j == x)
                  continue;

                  mat2.v[subi][subj].SetImaginar(this->v[i][j].GetImaginar());
                  mat2.v[subi][subj].SetReal(this->v[i][j].GetReal());
                  subj++;
               }
               subi++;
            }
            mat2.SetDim(mat2.GetDim()-1);
      nr.SetReal(nr.GetReal()+   this->v[0][x].GetReal()*pow(-1, x)*mat2.determinant().GetReal()-   this->v[0][x].GetImaginar()*pow(-1, x)*mat2.determinant().GetImaginar());
        nr.SetImaginar(nr.GetImaginar()+   this->v[0][x].GetReal()*pow(-1, x)*mat2.determinant().GetImaginar()-   this->v[0][x].GetImaginar()*pow(-1, x)*mat2.determinant().GetReal());




      }
   }return nr;
}


Matrice_oarecare* Read_N_elements(int n){
    int i;
    Matrice_oarecare* v=new Matrice_oarecare[n];

for(i=0;i<n;i++)
    cin>>v[i];if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");

    return v;
}
Matrice_patratica* Read_N_elements2(int n){
    int i;
    Matrice_patratica* v=new Matrice_patratica[n];

for(i=0;i<n;i++)
    cin>>v[i];if (cin.fail()) throw runtime_error("Nu ati introdus un numar\n");

    return v;
}
