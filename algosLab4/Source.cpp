#include <iostream>
#include <Windows.h>

int*** initStorageArray(int size)
{	
	int*** storageArray = new int** [size];
	for (size_t i = 0; i < size+1; ++i)
	{
		storageArray[i] = new int* [size];
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			storageArray[i][j] = new int[size];
			for (size_t k = 0; k < size; ++k)
			{
				storageArray[i][j][k] = -1;
			}
		}
	}

	return storageArray;
}
#define MAXHOUSES 100
int*** storageArray = initStorageArray(MAXHOUSES);

int housePermutations(int n, int leftSide, int rightSide)
{	
	if (leftSide > n || rightSide > n) return 0;
	if (leftSide < 1 || rightSide < 1) return 0;
	if (n == 1)
	{
		if (leftSide == 1 && rightSide == 1)
			return 1;
		else
			return 0;
	}
	if (storageArray[n][leftSide][rightSide] != -1) return storageArray[n][leftSide][rightSide];

	storageArray[n][leftSide][rightSide] = housePermutations(n - 1, leftSide - 1, rightSide) 
										  +housePermutations(n - 1, leftSide, rightSide - 1) 
		                                  +(n - 2) * housePermutations(n - 1, leftSide, rightSide);

	return storageArray[n][leftSide][rightSide];
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n; // n < MAXHOUSES
	int leftSide, rightSide;

	std::cout << "Введите кол-во домов: "; std::cin >> n;
	std::cout << "Видимых слева: "; std::cin >> leftSide;
	std::cout << "Видимых справа: "; std::cin >> rightSide;

	int permutationsAmount = housePermutations(n, leftSide, rightSide);
	std::cout << "Кол-во перестановок: " << permutationsAmount;
}