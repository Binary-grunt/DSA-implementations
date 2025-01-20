#include <stdio.h>

// Function to print the elements of an array
void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d,  ", i, arr[i]);
  }
  printf("\n");
}

// Function to insert an element into an array
void insertElement(int arr[], int el, int pos, int *n) {
  // Shift elements to the right to make space for the new element
  for (int i = *n; i >= pos; i--) {
    arr[i] = arr[i - 1];
  }
  arr[pos - 1] = el;
  (*n)++;
}

int main() {
  int arr[20] = {12, 45, 30, 22, 60};
  int el = 50, pos = 4, n = 5;

  printf("Array elements before insertion:\n");
  printArr(arr, n);

  // Insert the element into the array
  insertElement(arr, el, pos, &n);

  printf("Array elements after insertion:\n");
  printArr(arr, n);

  return 0;
}
