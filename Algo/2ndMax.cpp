#include<iostream>
using namespace std;

int main()
{
    int arr[]={3,4,6,8,1},size=5,max=0,Smax=0;
    if(arr[0]>arr[1]){
        max=arr[0];
        Smax=arr[1];
    }
    else{
        max=arr[1];
        Smax=arr[0];
    }
    for(int i=2;i<size;i++){
        if(arr[i]>max){
            Smax=max;
            max=arr[i];
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nSecond maximum is "<<Smax;
    return 0;
}
