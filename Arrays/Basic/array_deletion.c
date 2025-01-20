#include <stdio.h>

// Function to print the elements of an array
void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d, ", i, arr[i]);
  }
  printf("\n");
}

// Function to delete an element from the array
int deleteElement(int arr[], int k, int *n) {
  int found = 0;
  // Search for the element and shift elements if found
  for (int i = 0; i < *n; i++) {
    if (arr[i] == k) {
      found = 1;
    }
    if (found && i < *n - 1) {
      arr[i] = arr[i + 1];
    }
  }

  if (found) {
    (*n)--; // Reduce the size of the array
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int arr[] = {18, 30, 15, 70, 12};
  int k = 30, n = 5;

  printf("Given array elements are:\n");
  printArr(arr, n);

  // Attempt to delete an element
  if (deleteElement(arr, k, &n)) {
    printf("\nElement %d deleted successfully.\n", k);
  } else {
    printf("\nElement %d not found in the array.\n", k);
  }

  printf("\nElements of array after deletion:\n");
  printArr(arr, n);
}
