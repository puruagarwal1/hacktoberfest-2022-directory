#include <iostream>
using namespace std;

void CheckDuplicate(int arr[], int size) {
    int key=arr[0];

    for(int j=0; j<size; j++) {
        for(int i=j+1; i<size; i++) {
            if(arr[i] == key) {
                cout<<endl<<"Duplicate: "<<key;
                arr[i] = NULL;
                continue;
            }
        }
        key = arr[j+1];
    }
}

int main() {
    int arr[100], n;
    cout<<"\nEnter the size of array: ";
    cin>>n;

    cout<<"\nEnter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    CheckDuplicate(arr, n);

    return 0;
}