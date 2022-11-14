// laba_4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// 18 Вариант
#include <iostream>
using namespace std;

int input(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Элемент [" << i << "]= ";
        cin >> a[i];
    }
    return *a;
}

void output(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool prog(int* a, int n)
{
    bool flag;
    for (int i = 0; i < (n - 1); i++)
    {
        if (a[i] == a[i + 1])
        {
            cout << "true"<<" ";
            flag = true;
        }
        else
        {
            cout << "false"<<" ";
            flag=false;
        }
    }
    cout << endl;
    return flag;
}

int main()
{
    int n;
    double q, m;
    bool flagx=true, flagy=true;
    setlocale(LC_ALL, "Russian");
    cout << "Размер массива ";
    cin >> n;
    int* x = new int[n];
    int* y = new int[n];
    input(x, n);
    output(x, n);
    flagx = prog(x, n);
    input(y, n);
    output(y, n);
    flagy = prog(y, n);
    if (flagx == true and flagy == true)
    {
        cout << "На сколько увеличить первый массив?" << endl << "- ";
        cin >> q;
        cout << "На сколько увеличить второй массив?" << endl << "- ";
        cin >> m;
        for (int i = 0; i < n; i++)
        {
            x[i] += q;
            y[i] += m;
        }
        output(x, n);
        output(y, n);
    }
    if (flagx==false)
    {
        cout << "Элементы первого массива не совпадают" << endl;
    }
    if (flagy == false)
    {
        cout << "Элементы второго массива не совпадают" << endl;
    }
    system("pause");
}