#include <iostream>
#include <stdexcept> // For exceptions
using namespace std;

/**
 * Class: DynamicArray
 * --------------------
 * This class represents a dynamic array that supports resizing
 * when the capacity is exceeded. It allows appending elements,
 * deleting elements at a specific index, and displaying the array.
 */
class DynamicArray {
private:
  int *data;    // Pointer to the dynamically allocated array
  int size;     // Current number of elements in the array
  int capacity; // Maximum capacity of the array before resizing

  /**
   * Method: resize
   * --------------
   * Resizes the array to a new capacity, copying over the old elements.
   * Complexity:
   * - Time: O(n), where n is the current size of the array.
   * - Space: O(n) for the new memory allocation.
   */
  void resize() {
    capacity *= 2; // Double the capacity
    int *newData =
        new int[capacity]; // Allocate a new array with larger capacity

    // Copy existing elements to the new array
    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }

    delete[] data;  // Free the old array memory
    data = newData; // Point to the new array
  }

public:
  /**
   * Constructor: DynamicArray
   * --------------------------
   * Initializes the dynamic array with a given initial capacity.
   * Allocates memory for the array and sets size to 0.
   *
   * @param capacity - The initial capacity of the array.
   * @throws std::invalid_argument if the initial capacity is not positive.
   */
  DynamicArray(int capacity) {
    if (capacity <= 0) {
      throw invalid_argument("Capacity must be a positive integer.");
    }
    this->capacity = capacity;      // Set the initial capacity
    this->size = 0;                 // Initially, the array is empty
    this->data = new int[capacity]; // Dynamically allocate memory for the array
  }

  /**
   * Method: append
   * --------------
   * Appends a new value to the end of the array. If the array
   * is full, it doubles the capacity by resizing.
   *
   * Complexity:
   * - Time: O(1) on average, O(n) in the worst case (when resizing is
   * triggered).
   * - Space: O(n) due to memory reallocation during resizing.
   *
   * @param value - The value to append to the array.
   */
  void append(int value) {
    if (size == capacity) { // Check if resizing is needed
      resize();
    }
    data[size++] = value; // Add the new value and increment size
  }

  /**
   * Method: deleteAt
   * -----------------
   * Deletes an element at the specified index. All subsequent
   * elements are shifted left to fill the gap.
   *
   * Complexity:
   * - Time: O(n), where n is the size of the array.
   * - Space: O(1).
   *
   * @param index - The index of the element to delete.
   * @throws std::out_of_range if the index is invalid.
   */
  void deleteAt(int index) {
    if (index < 0 || index >= size) {
      throw out_of_range("Index out of bounds");
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
      data[i] = data[i + 1];
    }

    size--; // Reduce the size of the array
  }

  /**
   * Method: display
   * ----------------
   * Displays all the elements of the array.
   *
   * Complexity:
   * - Time: O(n), where n is the size of the array.
   * - Space: O(1).
   */
  void display() const {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  /**
   * Destructor: ~DynamicArray
   * --------------------------
   * Releases the dynamically allocated memory to prevent memory leaks.
   */
  ~DynamicArray() {
    delete[] data; // Free the memory allocated for the array
  }
};

/**
 * Function: main
 * --------------
 * Demonstrates the functionality of the DynamicArray class.
 */
int main() {
  try {
    DynamicArray arr(2);

    // Append elements to the array
    arr.append(10);
    arr.append(20);
    arr.append(30); // This will trigger a resize
    arr.display();  // Output: Array: 10 20 30

    // Delete an element at index 1
    arr.deleteAt(1);
    arr.display(); // Output: Array: 10 30

    // Attempt to delete with an invalid index
    arr.deleteAt(5); // Throws an exception
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0; // The destructor will automatically clean up the memory
}
