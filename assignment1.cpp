//Shell sort in C++

#include <iostream>
using namespace std;
 void shellSort(int arr[] , int n){
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int temp = arr[i];
            int j;
            for(j=i; j>=gap && arr[j-gap]>temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
 }

 int main(){
    int n;
    cout<<"\nEnter the size of the array:";
    cin>>n;
    int arr[n];

    cout<<"\nEnter the elements to sort:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    shellSort(arr,n);

    cout<<"\nElements after sorting:"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
 }
