#include "Task_1.h"
#include "Levenshtein.h"
#include <iostream>
#include <cmath>
#include <memory.h>
#include "LCS.h"

using namespace std;
void Task1();
void Task2();
void Task3();
void Task5();

void main()
{
	setlocale(LC_ALL, "rus");

	Task1();
	cout << "-----------------\n\n\n";
	// Task2();
	cout << "-----------------\n\n\n";
	Task3();
	cout << "-----------------\n\n\n";
	Task5();
}

void Task1()
{
	char* str250 = getString(250);
	char* str300 = getString(300);
	cout << "250 символов = " << str250 << endl << endl;
	cout << "300 символов = " << str300 << endl << endl;
}

void Task2()
{
	clock_t t1 = 0, t2 = 0, t3, t4;
	char x[] = "abcdefghklmnoxm", y[] = "xyabcdefghomnkm";
	int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	std::cout << std::endl << "-- длина --- рекурсия -- динамическое ---" << std::endl;
	for (int i = 8; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(i, x, i - 2, y);
		t2 = clock();
		t3 = clock();
		levenshtein(i, x, i - 2, y);
		t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC)
			<< "   " << std::setw(10) << ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC) << std::endl;
	}
}

void Task3()
{
	char x[] = "кол", y[] = "столб";
	int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
	int l = levenshtein_r(lx, x, ly, y);
	cout << "Результат = " << l << endl << endl;
}

void Task5()
{
	clock_t t1 = 0;
	clock_t t2 = 0;
	clock_t t3 = 0;
	clock_t t4 = 0;

	char Z[100] = "";
	char X[] = "QVTQVTOWNFSTHIKQHSHO";
	char Y[] = "RDFGHTFJGTWHYK";

	t1 = clock();
	int s = lcs(sizeof(X) - 1, X, sizeof(Y) - 1, Y);
	t2 = clock();

	t3 = clock();
	int l = lcsd(X, Y, Z);
	t4 = clock();

	cout << "\n-- вычисление длины LCS для X и Y";
	cout << "\n-- последовательность X: " << X;
	cout << "\n-- последовательность Y: " << Y;
	cout << "\n-- LCS:                  " << Z;

	cout << "\n-- длина LCS: (рекурсия) " << s;
	cout << "\n-- длина LCS: (дин.пр.)  " << l << "\n";

	cout << "\nВремя вычисления LCS:\n";
	cout << "рекурсия:  " << (t2 - t1);
	cout << "\nдин.про.:  " << (t4 - t3) << "\n";
}