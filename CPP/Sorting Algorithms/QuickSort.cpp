#include <bits/stdc++.h>
using namespace std;

int partitionArray(int arr[], int start, int end) {
    int pivot=arr[start], count=0;

    for(int i=start; i<=end; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }

    int index = start+count;
    swap(arr[start], arr[index]);

    int i=start, j=end;

    while(i<index && j>index) {
        if(arr[i]>pivot && arr[j]<pivot) {
            swap(arr[i++], arr[j--]);
        } else if(arr[i]<pivot) {
            i++;
        } else if(arr[j]>pivot){
            j--;
        }
    }
}

void quickSort(int arr[], int start, int end) {
    if(start>=end) {
        return;
    }

    int p = partitionArray(arr, start, end);

    quickSort(arr, start, p);
    quickSort(arr, p+1, end);
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int *arr = new int[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    cout<<"\nThe sorted array is: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}