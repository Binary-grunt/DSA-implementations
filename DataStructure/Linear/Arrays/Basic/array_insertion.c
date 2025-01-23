#include <stdio.h>

// Function to print the elements of an array
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = %d,  ", i, arr[i]);
	}
	printf("\n");
}

// Function to insert an element into an array
void insert_arr(int arr[], int target, int pos, int *n)
{
	// Shift elements to the right to make space for the new element
	for (int i = *n; i >= pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos - 1] = target;
	(*n)++;
}

int main()
{
	int arr[20] = {12, 45, 30, 22, 60};
	int target = 30, pos = 4;
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Array elements before insertion:\n");
	print_arr(arr, n);

	// Insert the element into the array
	insert_arr(arr, target, pos, &n);

	printf("Array elements after insertion:\n");
	print_arr(arr, n);

	return 0;
}
