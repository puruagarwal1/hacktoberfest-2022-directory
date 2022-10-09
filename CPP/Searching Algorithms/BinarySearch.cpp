#include <iostream>
using namespace std;

void SortAscending(int arr[], int size) {
    for(int i=0; i<(size-2); i++) {
        for(int j=0; j<(size-1-i); j++) {
            if(arr[j] > arr[j+1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int BinarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    int mid = ((start/2) + (end/2));
    // int mid = (start + (end - start)/2);

    while(start <= end) {
        
        if(arr[mid] == key) {
            return mid;
        }
        
        if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        
        mid = ((start/2) + (end/2));
        // mid = (start + (end - start)/2);
    }

    return -1;
}

int main() {
    int arr[100], n, key;

    cout<<"\nEnter the size of array: ";
    cin>>n;

    cout<<"\nEnter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nEnter the element to search in the array: ";
    cin>>key;

    SortAscending(arr, n);

    cout<<"\n\nWe need to sort the array for binary search method. So, the sorted array is: \n";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<"  ";
    }

    int index = BinarySearch(arr, n, key);

    if(index == -1)
        cout<<"\nThe key element "<<key<<" is not found in the array.\n";
    else    
        cout<<"\nThe key element "<<key<<" is found in the array at position no "<<index+1<<endl;

    return 0;
}