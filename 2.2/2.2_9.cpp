#include <iostream>
#include <math.h>
#define N 5 // предел массива

using namespace std;

int main()
{
    int x[N], y[N];
    double sum = 0.0;
    int counter = 0;
    int A;
    int n;
    
    cout << "\n Please, enter A = "; 
    cin >> A;
    
    
    for (int i = 0; i < N; i++)
    {
        cout << "x [" << i << "] = ";
        cin >> x[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        cout << "y [" << i << "] = ";
        cin>> y[i];
    }
    
    for (int i = 1; i <= N; i++)
    {
        if(x[i] * y [i] <= A)
        {
            cout << "\nsum = " << sum;
            sum += x[i] * y[i];
            counter++;
        }
    }
    cout << "\n Result sum = " << sum << endl;
    cout << "\n conter = " << counter << endl;
    return 0;
}