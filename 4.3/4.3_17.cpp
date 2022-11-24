// laba_4_3_17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void input(int* x, int lenx)
{
	for (int i = 0; i < lenx; i++)
	{
		cout << "[" << i << "]= ";
		cin >> x[i];
	}
}

void output(int* x, int lenx)
{
	for (int i = 0; i < lenx; i++)
	{
		cout << x[i] << " ";
	}
}

int prog(int lenX, int leftborderX, int rightborderX, int* X)
{
	int sum = 0;
	for (int i = 0; i < lenX; i++)
	{
		if (X[i] >= leftborderX and X[i] <= rightborderX)
		{
			sum += X[i];
		}
	}
	return sum;
}

int main()
{
	int lenA, lenB, lenC, leftborder, rightborder, resA, resB, resC;
	setlocale(LC_ALL, "Russian");
	cout << "Длина А: ";
	cin >> lenA;
	cout << "Длина B: ";
	cin >> lenB;
	cout << "Длина C: ";
	cin >> lenC;
	cout << endl;
	int* A = new int[lenA];
	input(A, lenA);
	cout << "A: ";
	output(A, lenA);
	cout << endl;
	int* B = new int[lenB];
	input(B, lenB);
	cout << "B: ";
	output(B, lenB);
	cout << endl;
	int* C = new int[lenC];
	input(C, lenC);
	cout << "C: ";
	output(C, lenC);
	cout << endl;
	cout << "Левая граница поиска: ";
	cin >> leftborder;
	cout << "Правая граница поиска: ";
	cin >> rightborder;
	resA = prog(lenA, leftborder, rightborder, A);
	cout << "Результат А " << resA << endl;
	resB = prog(lenB, leftborder, rightborder, B);
	cout << "Результат В " << resB << endl;
	resC = prog(lenC, leftborder, rightborder, C);
	cout << "Результат С " << resC << endl;
	if (resA > resB and resA > resC)
	{
		cout << "Наибольшее значение в массиве А" << endl;
	}
	if (resB > resA and resB > resC)
	{
		cout << "Наибольшее значение в массиве В" << endl;
	}
	if (resC > resA and resC > resB)
	{
		cout << "Наибольшее значение в массиве C" << endl;
	}
	if (resA == resB and resB != resC)
	{
		cout << "Результаты А и В совпадают" << endl;
	}
	if (resB == resC and resC != resA)
	{
		cout << "Результаты B и C совпадают" << endl;
	}
	if (resC == resA and resC != resB)
	{
		cout << "Результаты А и C совпадают" << endl;
	}
	if (resA == resB and resB == resC)
	{
		cout << "Результаты А B C совпадают" << endl;
	}
	system("pause");
}