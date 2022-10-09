#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int arr[], int start, int end) {
    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *firstArray = new int[len1];
    int *secondArray = new int[len2];

    // Coping both arrays
    int index = start;
    for(int i=0; i<len1; i++) {
        firstArray[i] = arr[index++];
    }

    index = mid + 1;
    for(int i=0; i<len2; i++) {
        secondArray[i] = arr[index++];
    }

    // Merging both arrays
    int i = 0;
    int j = 0;
    index = start;

    while(i<len1 && j<len2) {
        if(firstArray[i] < secondArray[j]) {
            arr[index++] = firstArray[i++];
        } else if(firstArray[i] > secondArray[j]) {
            arr[index++] = secondArray[j++];
        } else {
            arr[index++] = firstArray[i++];
            arr[index++] = secondArray[j++];
        }
    }

    while(i<len1) {
        arr[index++] = firstArray[i++];
    }

    while(j<len2) {
        arr[index++] = secondArray[j++];
    }

    // Deleting the dynamic allocated memory to avoid memory leak
    delete []firstArray;
    delete []secondArray;
}

void mergeSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }

    int mid = start + (end-start)/2;

    // Sorting left array
    mergeSort(arr, start, mid);

    // Sorting right array
    mergeSort(arr, mid+1, end);

    // Merging both sorted arrays
    mergeArrays(arr, start, end);
}

int main() {
    int arr[100], n;

    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    cout<<"\nThe sorted array is: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}