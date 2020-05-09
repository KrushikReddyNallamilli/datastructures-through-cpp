#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
const int  MaxSize = 100;
typedef struct 
{
int Coef;
int Exp;
} polynomial_term;

class Polynomial
{
private :
polynomial_term Poly [MaxSize];
int Total_Terms;
public :
Polynomial() { Total_Terms=0; }

void Read_Poly();
void Display_Poly( );
double Evaluate(double value);
Polynomial Add_Poly (Polynomial B);
//Polynomial Mult_Poly (Polynomial B);
};
/*
Polynomial Polynomial :: Mult_Poly(Polynomial B)
{
int flag, M,N;
Polynomial D;
int NewTerm_exp;
float NewTerm_coef;
int i,j,k,p;
i = j = k = 0;
// i and j are indices indicating current terms of polynomials A & B respectively
// K is the index pointing to current position in C where new term is to be added
int TmpIndex;
// TmpIndex is used to traverse polynomial C for inserting new term at proper location
M=Total_Terms;
N= B.Total_Terms;
while (i< M)
{
j = 0;
while (j < N)
{
NewTerm_exp = Poly[i].Exp + B.Poly[j].Exp;
NewTerm_coef = Poly[i].Coef * B. Poly [j].Coef;
TmpIndex = 0;
flag = 0;
while (TmpIndex< k ) // Insert NewTerm in Polynomial C
{
if(D.Poly[TmpIndex].Exp==NewTerm_exp)
// search matching exponent
{
flag = 1;
break;
}
//else
//if (D.Poly[TmpIndex].Exp<NewTerm_exp)
//break;
TmpIndex++;
}
if (flag) // if found add coeficients
D.Poly[TmpIndex].Coef = D.Poly[TmpIndex].Coef+NewTerm_coef;
else // else add at last location or in between
{
	D.Poly [k].Exp = NewTerm_exp;
	D.Poly [k].Coef = NewTerm_coef;
		k++;
}
j++;
}
i++;
}
D.Total_Terms=k;
return (D);
} */

Polynomial Polynomial :: Add_Poly( Polynomial B)
{
int i,j,k;
i = j = k = 0;
Polynomial C;
while (i<Total_Terms && j <B.Total_Terms)
{
if(Poly[i].Exp == B.Poly[j].Exp)
{
C.Poly[k].Coef = Poly[i].Coef + B.Poly[j].Coef;
C.Poly[k].Exp = Poly[i].Exp;
i++; j++; k++;
}
else
if(Poly[i].Exp>B.Poly[j].Exp)
{
C.Poly[k].Coef = Poly[i].Coef;
C.Poly[k].Exp = Poly[i].Exp;
i++; k++;
}
else
{
C.Poly[k].Coef = B.Poly[i].Coef;
C.Poly[k].Exp = B.Poly[i].Exp;
j++; k++;
}
}// end of while
while (i<Total_Terms)
{
C.Poly[k].Coef = Poly[i].Coef;
C.Poly[k].Exp = Poly[i].Exp;
i ++; k++;
}
while (j < B. Total_Terms)
{
C.Poly[k].Coef = B.Poly[i].Coef;
C.Poly[k].Exp = B.Poly[i].Exp;
j++; k++;
}
C.Total_Terms = k;
return C;
} // end of function
double Polynomial :: Evaluate(double Value)
{ int i = 0;
double result = 0;
while (i<Total_Terms)
{
result+=Poly[i].Coef*pow(Value,Poly[i].Exp);
// pow( ) is exponential function to compute xy
i++ ;
}
return result;
}
void Polynomial :: Read_Poly( )
{
int i;
cout<< "\n\nLet us read the polynomial now" <<endl;
cout<<"\n\nEnter total number of terms in polynomial";
cin>>Total_Terms;
for(i=0; i<Total_Terms; i++)
{
cout<< "Enter Exponent of" << i+1<<"Term";
cin>>Poly[i].Exp;
cout<< "Enter Coefficient of" << i+1<< "Term";
cin>>Poly[i].Coef;
}
}
void Polynomial :: Display_Poly( )
{
int i;
for(i=0; i<Total_Terms; i++)
cout<< Poly[i].Coef<< "x^" << Poly[i].Exp<<"+";
cout<<"\b" <<endl;
}
int main( )
{
Polynomial A,B,D, C;
double answer;
A.Read_Poly( );
B.Read_Poly( );
A.Display_Poly();
B.Display_Poly();
//double answer;

answer = A.Evaluate(2); 
cout<<"\n\n\t After evaluation Result = "<<answer;
C = A.Add_Poly(B);
cout<<"\n\n\t Addition of 2 polynomial is  = \n\n\t";
C.Display_Poly();
//D = A.Mult_Poly(B);
//cout<<"\n\n\t Multiplication of 2 polynomial is  = \n\n\t";
//D.Display_Poly();
	getch();
}
