// Concept
// Insert an element from the unsorted array to its correct position in the
// sorted array

// Complexity Analysis

// TIME COMPLEXITY
// The time complexity of the Insertion Sort algorithm is O(n^2) in the average and worst cases, 
//and O(n) in the best case.
// it's important to note that while Insertion Sort has a quadratic time complexity, it can be efficient for small input sizes or PARTIALLY SORTED ARRAYS.
//For larger input sizes or when sorting performance is critical, more efficient sorting algorithms like QuickSort or MergeSort are typically used.

// SPACE COMPLEXITY
//The space complexity of the Insertion Sort algorithm is O(1) since it sorts the array in-place, without requiring
//additional memory that grows with the input size. In other words, the algorithm uses a constant amount of extra memory,
// regardless of the size of the input array.

#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 8, 12, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    insertionSort(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

