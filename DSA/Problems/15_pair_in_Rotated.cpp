
// C++ code to implement the approach
 
#include <bits/stdc++.h>
using namespace std;
 
// This function returns true if arr[0..n-1]
// has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x){
                return true;
            }
        }
    }
    return false;
}
// Driver code
int main()
{
    int arr[] = { 11, 15, 6, 8, 9, 10 };
    int X = 16;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (pairInSortedRotated(arr, N, X))
        cout << "true";
    else
        cout << "false";
 
    return 0;
}