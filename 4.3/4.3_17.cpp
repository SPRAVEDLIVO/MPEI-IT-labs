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

double prog(int leftborderX, int rightborderX, int* X)
{
	double pr = 0;
	for (int i = leftborderX; i <= rightborderX; i++)
	{
		pr += X[i];
	}
	return pr;
}

int main()
{
	int lenA, lenB, lenC, leftborderA, rightborderA, leftborderB, rightborderB, leftborderC, rightborderC;
	double resA, resB, resC;
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
	cout << "Примечание. Далее следует ввод границ подсчётов, программа не даст ввести значения, выходящие за пределы массивов" << endl;
	// Ввод границ. Не понимаю пока, что делать в случае, когда интервал выходит за границы массива
	while (true)
	{
		cout << "Введите левую границу для А: ";
		cin >> leftborderA;
		cout << "Введите правую границу для А: ";
		cin >> rightborderA;
		if (leftborderA < lenA and rightborderA < lenA and leftborderA >= 0 and leftborderA <= rightborderA)
		{
			break;
		}
	}
	while (true)
	{
		cout << "Введите левую границу для В: ";
		cin >> leftborderB;
		cout << "Введите правую границу для В: ";
		cin >> rightborderB;
		if (leftborderB < lenB and rightborderB < lenB and leftborderB >= 0 and leftborderB <= rightborderB)
		{
			break;
		}
	}
	while (true)
	{
		cout << "Введите левую границу для C: ";
		cin >> leftborderC;
		cout << "Введите правую границу для C: ";
		cin >> rightborderC;
		if (leftborderC < lenC and rightborderC < lenC and leftborderC >= 0 and leftborderC <= rightborderC)
		{
			break;
		}
	}
	resA = prog(leftborderA, rightborderA, A);
	cout << "Результат А " << resA << endl;
	resB = prog(leftborderB, rightborderB, B);
	cout << "Результат В " << resB << endl;
	resC = prog(leftborderC, rightborderC, C);
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
	if (resA == resB)
	{
		cout << "Результаты А и В совпадают" << endl;
	}
	if (resB == resC)
	{
		cout << "Результаты B и C совпадают" << endl;
	}
	if (resC == resA)
	{
		cout << "Результаты А и C совпадают" << endl;
	}
	if (resA == resB == resC)
	{
		cout << "Результаты А B C совпадают" << endl;
	}
}