#include "Task_1.h"
#include <stdlib.h>

char* getString(int size)
{
	srand(time(NULL));
	char* str = new char[size] {};
	for (int i = 0; i <= size; i++)
	{
		str[i] = 65 + rand() % 26;
	}
	return str;
}