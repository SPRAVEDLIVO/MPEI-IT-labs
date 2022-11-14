// laba__4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int input(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	}
    return **a;
}

void output(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int prog (int** a, int m, int n, double* sr, double max)
{
	double res;
	for (int i = 0; i < m; i++)
	{
		double s=0, k=0, max=0;
		for (int j = 0; j < n; j++)
		{
			s += a[i][j];
			k += 1;
		}
		res = s / k;
		cout << res << " " << s << " " << k << endl;
		sr[i]=res;
	}
	max = sr[0];
	for (int i = 0; i < m; i++)
	{
		if (sr[i] > max)
		{
			max = i;
		}
	}
	cout << max;
	return res;
}

double prog1(int** a, int n, int i) 
{
	double res, s = 0, k = 0;
	for (int j = 0; j < n; j++)
	{
		s += a[i][j];
		k += 1;
	}
	res = s / k;
	cout << res << " ";
	return res;
}
//main 
int main()
{
	double max, nummax=0;
	int m, n;
	setlocale(LC_ALL, "Russian");
	cout << "строки = ";
	cin >> m;
	cout << "столбцы = ";
	cin >> n;
	double* sr = new double[m];
	int** x = new int* [m];
	for (int i = 0; i < m; i++)
		x[i] = new int[n];
	**x = input(x, m, n);
	output(x, m, n);
	for (int i = 0; i < m; i++)
	{
		sr[i] = prog1(x, n, i);
	}
	cout << endl;
	max = sr[0];
	for (int i = 0; i < m; i++)
	{
		if (sr[i] > max)
		{
			max = sr[i];
			nummax = i;
		}
	}
	cout << "Номер строки с наибольшим значением спелнего арифметического - " << nummax;
}

