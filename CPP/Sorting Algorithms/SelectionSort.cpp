#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i; j<n; j++) {
            if(arr[min] > arr[j])
                min = j;
        }
        
        swap(arr[i], arr[min]);
    }
}

int main() {
    int arr[100], n;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    SelectionSort(arr, n);

    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<"  ";
    }

    return 0;
}