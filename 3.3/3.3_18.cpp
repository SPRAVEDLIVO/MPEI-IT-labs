#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	float s = 0, k = 0;
	cout << "n=";
	cin >> n;
	int** a = new int* [n]; 
	for (int i = 0; i < n; i++) 
		a[i] = new int[n]; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i][n - 1] == 1)
		{
			k += 1;
			for (int j = 0; j < n; j++)
			{
				s += a[i][j];
			}
		}
	}
	if (k == 0)
	{
		cout << "В массиве нет строк, оканчивающихся на 1" << endl;
	}
	else
	{
		cout << "Среднее арифметическое: " << s << " " << k << " " << s / k;
	}
	
}