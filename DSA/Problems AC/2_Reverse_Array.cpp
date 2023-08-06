#include <iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int low=0,high=size-1;
    while(low<high){
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++,high--;
    }
}

int main() {
    int arr[] = {33, 44, 55, 41, 43};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array is: ";
    for (int element : arr) {
        cout << element << " ";
    }
    reverseArray(arr,size);
    // for (int i = 0; i < size / 2; i++) {
    //     int temp = arr[i];
    //     arr[i] = arr[size - 1 - i];//arr[i++]=arr[size--]
    //     arr[size - 1 - i] = temp;//arr[size]=temp
    // }

    cout << "\nReversed array is: ";
    for (int element : arr) {
        cout << element << " ";
    }

    return 0;
}
