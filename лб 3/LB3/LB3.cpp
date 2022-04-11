// LB3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int d[N][N] = { // 1    2    3    4     5        
					{ INF,  14, 28,  INF,   7 },    //  1
					{ 7,   INF,  22,  61,  74 },    //  2
					{ 9,  21,   INF,  86,   56 },    // 3 
					{ 24,  51,  28,   INF,   21 },    // 4
					{ 86,  73,  52,  20,    INF } };   // 5  
	int r[N];   /// результат 
	int s = salesman(
		N,          /// [in]  кол-во городов 
		(int*)d,    /// [in]  массив [n*n] расстояний 
		r           /// [out] массив [n] маршрут 0 x x x x  

	);
	cout << "\n-- Задача коммивояжера -- ";
	cout << "\n-- количество  городов: " << N;
	cout << "\n-- матрица расстояний : ";

	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < N; j++)

			if (d[i][j] != INF) cout << setw(3) << d[i][j] << " ";

			else cout << setw(3) << "INF" << " ";
	}

	cout << "\n-- оптимальный маршрут: ";
	for (int i = 0; i < N; i++)
		cout << r[i] + 1 << "-->";

	cout << 1;
	cout << "\n-- длина маршрута     : " << s << "\n";
	system("pause");
	return 0;
}