#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int const n = 5
    int C, counter=0;
    cout<<"Please, enter C = ";
    cin>>C;

    
    double A[n][n],x[n];


    cout<<"Please, enter elements of matrix : ";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout << "Enter element A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (A[j][i]>C) {
	        x[i]=1;
            counter++;
		 }
	        else {
	         x[i]=0;
		     }
        }
    }
cout <<"\n Massive x = ";
for (int i=0;i<n;i++)
	{  
    cout<<x[i]<<"  ";
}
cout <<"\n The number of matrix elements that exceed C = "<< counter;
}
