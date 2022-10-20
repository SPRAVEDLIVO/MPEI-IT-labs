#include <iostream>
 
using namespace std;
 
int main()
{
    const int n=2;
    const int m=3;
    float A[n][m];
    float R,T;
    int i, j, s;
    bool f = false;
    cout<<"\nVvedite elementy matricy A:\n";
 
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cin>>A[i][j];
        }
    }
 
    cout<<"\nMatrica A:\n";
 
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<"\nVvedite chislo T = \n";
    cin >> T;
    
    for (i=0;i<n;i++) {
        f = false;
 
        if ((abs(A[i][0]-A[i][2]) <= T) && (abs(A[i][1]-A[i][2]) <= T) && (abs(A[i][0]-A[i][1]) <= T)) {
            f=true;
        }
        
        cout << f;
        
        if (f == false) {
            break;
        }
        
 
        else {
            s=0;
            for (j=0;j<m;j++) {
                s+=A[i][j];
            }
            cout<<"\nSumma stroki "<<i<<" = "<<s<<endl; 
        }
    }
    return 0;
}