#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr, int maxValue) {
    int size = arr.size();
    std::vector<int> count(maxValue + 1, 0);
    std::vector<int> output(size);

    // Count the occurrences of each element
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the starting positions
    for (int i = 1; i <= maxValue; ++i) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted output array back to the original array
    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {9, 4, 7, 2, 1, 9, 5, 2};
    int maxValue = 9;

    countingSort(arr, maxValue);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
