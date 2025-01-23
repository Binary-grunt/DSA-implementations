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

// Function to search for an element in the array
void search_arr(int arr[], int target, int n)
{
	int found = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			printf("Element %d found in index %d\n ", arr[i], i);
			found = 1;
		}
	}
	if (!found)
	{
		printf("Element %d not found in the array.\n", target);
	}
}

int main()
{
	int arr[] = {18, 30, 15, 70, 12};
	int target = 30;
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Given array elements are:\n");
	print_arr(arr, n);

	// Search for an element in the array
	printf("\nSearching for element %d:\n", target);
	search_arr(arr, target, n);
}
