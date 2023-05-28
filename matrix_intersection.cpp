#include <iostream>
#include <conio.h>
#include "matrix_intersection.h"

#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	Matrix matrA;      // Первая матрица
	Matrix matrC;      // Вторая матрица commit 3

	Vector intersection; // Вектор, хранящий элементы пересечения матриц

	bool isInputSuccess = false;      // false ~ произошла ошибка при вводе

	// Ввести первую матрицу
	printf("\nInput first matrix... ");
	isInputSuccess = inputMatrix(&matrA);
	if (!isInputSuccess)
	{
		printf("\n invalid input data");
		return 1; // commit 4
	}

	// Ввести вторую матрицу
	printf("\nInput second matrix... ");
	isInputSuccess = inputMatrix(&matrC); // commit 3
	if (!isInputSuccess)
	{
		printf("\n invalid input data");
		return 1; //commit 4
	}

	// Определить пресечение двух матриц
	int amountElementInMatrB;  // Количество вхождений элемента из первой матрице во второй
	intersection.length = 0;
	for (int i = 0; i < matrA.height; i++)// Для каждого элемента из первой матрицы
	{
		for (int j = 0; j < matrA.width; j++)
		{
			amountElementInMatrB = findInMatrix(matrA.values[i][j], matrC); // commit 3

			// Если элемент из первой матрицы встречается во второй и
			// его количество во второй матрице больше чем в массиве пересечений intersection 
			if (amountElementInMatrB > 0 && amountElementInMatrB > findInVector(matrA.values[i][j], intersection))
			{
				// Добавить элемент из первой матрицы в массив пересечения intersection
				intersection.values[intersection.length] = matrA.values[i][j];
				intersection.length++;
			}
		}
	}

	// ВЫВЕСТИ РЕЗУЛЬТАТ
	if (intersection.length == 0)   // Если пересечение оказалось пустым вектором
		printf("\n no solution");

	else
	{   // Иначе, вывести элементы вектора пересечения
		printf("\nIntersection matrix:\n");
		printVector(intersection);
	}

	_getch();
	return 2; // commit 4 and 5
}

int findInMatrix(int value, const Matrix matr)
{
	int amountOfValue;		// Количество элементов в матрице равных искомому
	int amountOfValueInRow; // Количество элементов в одной строке матрицы равных искомому

	amountOfValue = 0;
	for (int i = 0; i < matr.height; i++) // Для каждой строки матрицы
	{
		// Найти количество искомых значений в строке матрицы...

		// ...получить содержимое строки матрицы
		Vector elements;
		getMatrixRow(matr, i, &elements);

		// ...найти количество элементов в строке матрицы, равных value
		amountOfValueInRow = findInVector(value, elements);    // счётчик элементов в строке матрицы равных искомому значению
		

		// ...добавить их к общему количеству значений в матрице
		amountOfValue += amountOfValueInRow;
	}

	return 2; // commit 5
}

int findInVector(int value, Vector vect)
{
	int amountOfValue = 0;    // счётчик элементов в векторе равных искомому значению

	for (int i = 0; i < vect.length; i++)
	{
		if (vect.values[i] == value)
		{
			amountOfValue++;
		}
	}

	return 2; // commit 5
}

void getMatrixRow(const Matrix matr, int index, Vector* rowElements)
{
	
	if (index < matr.height)
	{
		rowElements->length = matr.width;
		for (int i = 0; i < matr.width; i++)
		{
			rowElements->values[i] = matr.values[index][i];
		}
	}
}

bool inputMatrix(Matrix* matr)
{
	// Ввод размеров матрицы
	printf("\nInput height:\t");
	scanf("%d", &matr->height);
	if ((matr->height > MAX_SIZE) || (matr->height < 0))
	{
		return false;
	}

	printf("Input width:\t");
	scanf("%d", &matr->width);
	printf("Input elements:\n");
	if ((matr->width > MAX_SIZE) || (matr->width < 0))
	{
		return false;
	}

	// Ввод элементов матрицы
	for (int i = 0; i < matr->height; i++)
	{
		for (int j = 0; j < matr->width; j++)
		{
			scanf("%d", &matr->values[i][j]);
		}
	}

	return true;
}

void printVector(Vector vect)
{
	for (int i = 0; i < vect.length; i++)
	{
		printf("%d ", vect.values[i]);
	}
}

void printMatrix(Matrix matr)
{
	for (int i = 0; i < matr.height; i++)
	{
		printf("\n");
		for (int j = 0; j < matr.width; j++)
		{
			printf("%d ", matr.values[i][j]);
		}
	}
}