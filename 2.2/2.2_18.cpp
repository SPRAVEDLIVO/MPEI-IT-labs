﻿// laba 2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>;
#include <math.h>;
using namespace std;
#define N 20 
int main()
{
	setlocale(LC_ALL, "Russian");
	double XT, YT, B, X[N], Y[N], L[N], n, k=0, sumx=0, sumy=0;
	cout << "XT="; 
	cin >> XT;
	cout << "YT=";
	cin >> YT;
	cout << "B=";
	cin >> B;
	cout << "n=";
	cin >> n;
	cout << "=========" << endl;
	cout << "Введите координаты точек" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "         " << endl;
		cout << "X[" << i << "]=";
		cin >> X[i];
		cout << "Y[" << i << "]=";
		cin >> Y[i];
	} 
	cout << "         " << endl;
	cout << "=========" << endl;
	for (int i = 0; i < n; i++)
	{
		L[i] = sqrt(pow((X[i] - XT), 2) + pow((Y[i] - YT), 2));
		if (L[i] > B)
		{
			k += 1;
		}
		cout << "Длина " << i + 1 << "-го отрезка: ";
		cout << L[i] << endl;
	}
	cout << "Количество отрезков длиннее B: " << k << endl;
	for (int i = 0; i < n; i++)
	{
		sumx += X[i];
		sumy += Y[i];
	}
	cout << "=========" << endl;
	cout << "Средние координаты Х: " << sumx / n << endl;
	cout << "Средние координаты Y: " << sumy / n << endl;
	cout << "=========" << endl;
	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.