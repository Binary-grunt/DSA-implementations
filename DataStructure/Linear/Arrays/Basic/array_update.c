#include <stdio.h>

// Function to print the elements of an array
void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = %d, ", i, arr[i]);
	}
	printf("\n");
}

// Function to update an element in the array
void update_arr(int arr[], int n, int index, int newValue)
{
	if (index < 0 || index >= n)
	{
		printf("Error: Index %d is out of bounds.\n", index);
		return;
	}
	printf("Updating element at index %d from %d to %d.\n", index, arr[index], newValue);
	arr[index] = newValue;
}

int main()
{
	int arr[] = {18, 30, 15, 70, 12};
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = 2, newValue = 25;

	printf("Original array elements are:\n");
	print_arr(arr, n);

	// Update an element at a specific index
	update_arr(arr, n, index, newValue);

	printf("\nArray elements after update:\n");
	print_arr(arr, n);

	return 0;
}
