#include <iostream>
using namespace std;

int main() {
    int arr[] = {33, 44, 55, 41, 665, 43};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: ";
    for (int element : arr) {
        cout << element << " ";
    }

    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];//arr[i++]=arr[size--]
        arr[size - 1 - i] = temp;//arr[size]=temp
    }

    cout << "\nReversed array is: ";
    for (int element : arr) {
        cout << element << " ";
    }

    return 0;
}
