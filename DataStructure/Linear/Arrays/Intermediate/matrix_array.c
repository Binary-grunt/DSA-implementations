#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a matrix
int **allocateMatrix(int rows, int cols)
{
	int **matrix = (int **) malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int *) malloc(cols * sizeof(int));
	}
	return matrix;
}

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols)
{
	int **result = allocateMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return result;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int r1, int c1, int **matrix2, int r2, int c2)
{
	if (c1 != r2)
	{
		printf("Matrix multiplication not possible: Column of first != Row of "
		       "second\n");
		return NULL;
	}
	int **result = allocateMatrix(r1, c2);
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < c1; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}

// Function to free dynamically allocated memory of a matrix
void freeMatrix(int **matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

// Function to input elements of a matrix
void inputMatrix(int **matrix, int rows, int cols)
{
	printf("Enter elements for a %dx%d matrix:\n", rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

// Function to display the elements of a matrix
void displayMatrix(int **matrix, int rows, int cols)
{
	printf("Matrix (%dx%d):\n", rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

// Main function
int main()
{
	int rows1, cols1, rows2, cols2;

	// Input dimensions for the first matrix
	printf("Enter the number of rows and columns for the first matrix: ");
	scanf("%d %d", &rows1, &cols1);

	// Allocate and input first matrix
	int **matrix1 = allocateMatrix(rows1, cols1);
	inputMatrix(matrix1, rows1, cols1);

	// Input dimensions for the second matrix
	printf("Enter the number of rows and columns for the second matrix: ");
	scanf("%d %d", &rows2, &cols2);

	// Allocate and input second matrix
	int **matrix2 = allocateMatrix(rows2, cols2);
	inputMatrix(matrix2, rows2, cols2);

	// Display both matrices
	printf("\nMatrix 1:\n");
	displayMatrix(matrix1, rows1, cols1);

	printf("\nMatrix 2:\n");
	displayMatrix(matrix2, rows2, cols2);

	// Matrix addition
	if (rows1 == rows2 && cols1 == cols2)
	{
		int **additionResult = addMatrices(matrix1, matrix2, rows1, cols1);
		printf("\nResult of Matrix Addition:\n");
		displayMatrix(additionResult, rows1, cols1);
		freeMatrix(additionResult, rows1);
	}
	else
	{
		printf("\nMatrix addition not possible: Dimensions do not match.\n");
	}

	// Matrix multiplication
	int **multiplicationResult = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
	if (multiplicationResult != NULL)
	{
		printf("\nResult of Matrix Multiplication:\n");
		displayMatrix(multiplicationResult, rows1, cols2);
		freeMatrix(multiplicationResult, rows1);
	}

	// Free allocated memory
	freeMatrix(matrix1, rows1);
	freeMatrix(matrix2, rows2);

	return 0;
}
