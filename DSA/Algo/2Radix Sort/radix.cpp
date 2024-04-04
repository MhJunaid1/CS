#include <iostream>
#include <vector>

using namespace std;

// Function to get the maximum element from an array
int getMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[] so that arr[] now contains sorted numbers based on current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort function
void radixSort(vector<int>& arr) {
    int max = getMax(arr);

    // Do counting sort for every digit.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    radixSort(arr);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
/*
In this example, we first find the maximum number from the input array to determine the number of digits in the maximum number. Then, we perform counting sort for each digit (from the least significant to the most significant) using the countingSort function. The radixSort function calls countingSort for each digit, sorting the entire array based on each digit. Finally, the array is sorted using Radix Sort.*/
