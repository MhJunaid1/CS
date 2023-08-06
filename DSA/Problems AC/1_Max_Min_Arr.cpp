#include<iostream>
using namespace std;

int main()
{
    int arr[]={3,4,66,99,22},min=arr[0],max=arr[0];
    cout<<"The array is ";
    //range-based for loop instead of traditional for loop
    for (int element : arr)
    {
        cout<<element<<" ";
        if(element>max)
        {
            max=element;
        }
        if(element<min)
        {
            min=element;
        }
    }
    
    cout<<"\nMaximum element is "<<max<<"\n Minimum element is "<<min<<endl;
}