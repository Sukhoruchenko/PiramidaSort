#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;

void RandMas(int *a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}

void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
    cout << endl;
}

//Функция просеивания
void siftDown(int *a, int i, int n)
{   
	int j = 2 * i + 1;
	while (j <= n)
	{
		if (j + 1 <= n)
			{
			 if (a[j + 1] > a[j]) 
				 j = j + 1;
			}
		if (a[j] > a[i])
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i = j;
			j = 2 * i + 1;
		}
		else break;
	}
	
}

// Функция сортировки на куче
void HeapSort(int *a, int n)
{
	// Формируем нижний ряд пирамиды
	for (int i = (n / 2) - 1; i >= 0; i--)
		siftDown(a, i, n - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = n - 1; i >= 1; i--)
	{
		int t = a[0];
		a[0] = a[i];
		a[i] = t;
		siftDown(a, 0, i - 1);
	}
}

   void main()
{
	int  *a, n;
	cout << "input kol-vo elements: ";
	cin >> n;
	a = new int[n];
	RandMas(a, n);
	Output(a, n);
	cout << endl;
	HeapSort(a, n);
	Output(a, n);
	delete[] a;
	_getch();
}
