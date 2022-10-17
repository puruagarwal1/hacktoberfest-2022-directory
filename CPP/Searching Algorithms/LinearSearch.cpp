#include <iostream>
using namespace std;

int LinearSearch(int arr[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key)
            return i;
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

    cout<<"\nEnetr the key to search: ";
    cin>>key;

    int position = LinearSearch(arr, n, key);

    if(position != -1)
        cout<<endl<<"The element "<<key<<" is found in the array at position no. "<<position+1;
    else
        cout<<endl<<"The element is not found in the array";

    return 0;
}