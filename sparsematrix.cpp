#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
const int Max= 20;
class Sparse_Matrix
{
private:
	int Mat[Max][3];
public:
void Read_SparseMatrix();
void Print_SparseMatrix();

Sparse_Matrix Add_SparseMatrix (Sparse_Matrix S2) ;
Sparse_Matrix Simple_Transpose() ;

Sparse_Matrix Fast_Transpose ( ) ;

};
void Sparse_Matrix:: Read_SparseMatrix()
{
int n,i,j,ch,r1,c1;
char ans;
//clrscr();
cout<<"\n\nEnter the size of Matrix :\n";
cin>>Mat[0][0]>>Mat[0][1];
cout<<"Enter the total no. of non zero elements\n";
cin>>Mat[0][2];
	cout<<"\n\n Enter the row number, column number and value respectively";
	for(i=1;i<=Mat[0][2];i++)
	{
	cout<<"\n Enter "<<i<<" Record\t";
	cin>>Mat[i][0]>>Mat[i][1]>>Mat[i][2];
	cout<<"\n";
	}
}
void Sparse_Matrix:: Print_SparseMatrix()
{
int n,i,j,ch,r1,c1;

	cout<<"\n\n Sparse MAtrix = \n";
	cout<<"\t\t0\t1\t2\n";
	for(i=0;i<=Mat[0][2];i++)
	{
	cout<<"\n Row "<<i<<"\t";
	cout<<"\t"<<Mat[i][0]<<"\t"<<Mat[i][1]<<"\t"<<Mat[i][2];
	cout<<"\n";
	}

}

Sparse_Matrix Sparse_Matrix :: Add_SparseMatrix (Sparse_Matrix B)
{
Sparse_Matrix C;
int i, j, k, Row1, Row2, Col1, Col2,M1, M2 ;
Row1 = Mat[0][0];
Col1 = Mat[0][1];
M1 = Mat[0][2];
Row2=B.Mat[0][0];
Col2=B.Mat[0][1];
M2=B.Mat[0][2];
if(Row1==Row2 && Col1==Col2) // checking dimensions if1
{
i = j = k = 1;
C. Mat[0] [0] = Mat [0] [0];
C. Mat[0] [1] = Mat [0] [1];
while (i<= M1 && j <= M2) // while1
{
if (Mat [i] [0] == B.Mat[j][0]) // if2
{
if (Mat[i] [1] == B.Mat[j][1]) // if3
{
C.Mat[k][0] = Mat[i] [0];
C.Mat[k][1] = Mat[i] [1];
C.Mat[k][2] = Mat[i] [2] + B.Mat[j] [2];
i++; j++; k++;
}
else // else of if3
if (Mat[i] [1] < B. Mat[j] [1]) // if4
{
C.Mat[k] [0] = Mat [i] [0];
C.Mat[k] [1] = Mat [i] [1];
C.Mat[k] [2] = Mat [i] [2];
k ++; i++;
}
else // else if4
{
C. Mat [k] [0] = B. Mat [j] [0];
C. Mat [k] [1] = B. Mat [j] [1];
C. Mat [k] [2] = B. Mat [j] [2];
j++;k++;
}
}
else // else of if 2
if (Mat[i][0] < B. Mat[j] [0]) // if5
{
C. Mat [k] [0] = Mat [i] [0];
C. Mat [k] [1] = Mat [i] [1];
C. Mat [k] [2] = Mat [i] [2];
k++; i++;
}
else // else of if 5
{
C. Mat[k] [0] = B. Mat[j] [0];
C. Mat[k] [1] = B. Mat[j] [1];
C. Mat[k] [2] = B. Mat [j] [2];
k ++; j++;
}
} // end of while1

while (i<= M1) // while2
{
C. Mat[k] [0] = Mat [i] [0];
C. Mat [k] [1] = Mat [i] [1];
C. Mat[k] [2] = Mat [i] [2];
k++; i++;
} // end of while2
while (j <= M2) // while3
{
C.Mat[k] [0] = B. Mat [j] [0];
C.Mat [k] [1] = B. Mat [j] [1];
C.Mat[k] [2] = B. Mat [j] [2];
k++; j++;
} // end of while3
C.Mat[0] [2] = k-1;
return C;
} // end of if1 for checking dimensions
else
cout<<"Sorry as dimensions are not matching matrices can not be addedn\n";
}

Sparse_Matrix Sparse_Matrix ::Simple_Transpose( )
{
Sparse_Matrix B;
int Row, Col,i,j,k,T;
Row = Mat [0][0];
Col = Mat [0][1];
B. Mat [0][0] = Col;
B. Mat [0][1] = Row;
T = Mat [0][2];
B. Mat [0][2] = T;
if(T==0)
return B;
i = 1;
for( j=0; j<Col; j++)
for( k=1; k<=T; k++)
if (Mat [k][1] == j)
{
B.Mat[i][0]= j;
B.Mat[i][1]= Mat[k][0];
B.Mat[i][2]=Mat[k][2];
i++;
}

return B;
}

Sparse_Matrix Sparse_Matrix ::Fast_Transpose( )
{
Sparse_Matrix B;
int Row,Col,M,m, n, T, i, j, Freq[20], RowStartPos[20] ;
Row =Mat [0][0];
Col = Mat [0][1];
M = Mat [0][2];
B. Mat [0][0] = Col;
B. Mat [0][1] = Row;
B. Mat [0][2] = M;
if(M==0) return	B;
else
{
for (i=0;i<Col;i++)
	{
		Freq[i]=0;
	}
	for(i=1;i<=M;i++)
	{
		T=Mat[i][1];
		Freq[T]++;
	}
RowStartPos [0] =1;
for(i=1;i<Col;i++)
{ RowStartPos [i] = RowStartPos [i - 1] + Freq[i - 1];}

for(i=1;i<=M;i++)
{
j=Mat[i][1] ;
B.Mat[RowStartPos [j]][0] = Mat[i][1];
B.Mat[RowStartPos [j]][1] = Mat[i][0];
B.Mat[RowStartPos [j]][2] = Mat[i][2];
RowStartPos [j] = RowStartPos [j]+1;
}
}
return B;
}

int main()
{
Sparse_Matrix S1,S2,S3,S4,S5;

      S1.Read_SparseMatrix();
      S2.Read_SparseMatrix();
cout<<"\n\n Addition is = \n";
      S3=  S1.Add_SparseMatrix(S2);
     //	clrscr();
	   S1.Print_SparseMatrix();
	 S2.Print_SparseMatrix();
	 S3.Print_SparseMatrix();
	S4  = S1.Simple_Transpose();
	cout<<"\n\n Simple Transpose = \n";
	   S4.Print_SparseMatrix();
		S5=S1.Fast_Transpose();
		cout<<"\n\n Fast Transpose = \n";
		S5.Print_SparseMatrix();
	getch();
}

