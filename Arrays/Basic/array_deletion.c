#include <stdio.h>

// Function to print the elements of an array
void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d, ", i, arr[i]);
  }
  printf("\n");
}

// Function to delete an element from the array
int delete_arr(int arr[], int target, int *n) {
  int found = 0;
  // Search for the element and shift elements if found
  for (int i = 0; i < *n; i++) {
    if (arr[i] == target) {
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
  int target = 30;
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Given array elements are:\n");
  print_arr(arr, n);

  // Attempt to delete an element
  if (delete_arr(arr, target, &n)) {
    printf("\nElement %d deleted successfully.\n", target);
  } else {
    printf("\nElement %d not found in the array.\n", target);
  }

  printf("\nElements of array after deletion:\n");
  print_arr(arr, n);
}
