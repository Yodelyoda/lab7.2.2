#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Min(int** a, const int rowCount, const int colCount, int i, int j, int& min)
{
	if (a[i][j] < min)
		min = a[i][j];
	if (j < colCount - 1)
		Min(a, rowCount, colCount, i, j + 1, min);
	else
		if (i < rowCount - 1)
			Min(a, rowCount, colCount, i + 1, 0, min);
}
void Max(int** a, const int rowCount, const int colCount, int i, int j, int& max)
{
	if (a[i][j] > max)
		max = a[i][j];
	if (j < colCount - 1)
		Max(a, rowCount, colCount, i, j + 1, max);
	else
		if (i < rowCount - 1)
			Max(a, rowCount, colCount, i + 1, 0, max);
}
void Change(int** a, const int n, const int k, int& min, int& max)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (j % 2 != 0)
			{
				if (a[i][j] == min) a[i][j] = max;
				else if (a[i][j] == max) a[i][j] = min;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n, k;
	cout << "n = "; cin >> n;//rowCount
	cout << "k = "; cin >> k;//colCount
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n, k, Low, High, 0, 0);
	cout << endl;
	Print(a, n, k, 0, 0);
	int min = a[0][0];
	int max = a[0][0];
	Min(a, n, k, 0, 0, min);
	Max(a, n, k, 0, 0, max);
	Change(a, n, k, min, max);
	cout << endl;
	Print(a, n, k, 0, 0);
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}