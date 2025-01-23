#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *data;
	int  size;
	int  capacity;
} DynamicArray;

DynamicArray *createArray(int capacity)
{
	DynamicArray *arr = (DynamicArray *) malloc(sizeof(DynamicArray));
	arr->data = (int *) malloc(capacity * sizeof(int));
	arr->size = 0;
	arr->capacity = capacity;
	return arr;
}

void append(DynamicArray *arr, int value)
{
	if (arr->size == arr->capacity)
	{
		arr->capacity *= 2;
		arr->data = (int *) realloc(arr->data, arr->capacity * sizeof(int));
	}
	arr->data[arr->size++] = value;
}

void deleteAt(DynamicArray *arr, int index)
{
	if (index < 0 || index >= arr->size)
	{
		printf("Index hors limite\n");
		return;
	}
	for (int i = index; i < arr->size - 1; i++)
	{
		arr->data[i] = arr->data[i + 1];
	}
	arr->size--;
}

void display(DynamicArray *arr)
{
	printf("Array: ");
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void freeArray(DynamicArray *arr)
{
	free(arr->data);
	free(arr);
}

int main()
{
	DynamicArray *arr = createArray(2);

	append(arr, 10);
	append(arr, 20);
	append(arr, 30);
	display(arr);

	deleteAt(arr, 1);
	display(arr);

	freeArray(arr);
	return 0;
}
