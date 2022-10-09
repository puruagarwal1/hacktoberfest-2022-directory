#include <iostream>
using namespace std;

void sort(int arr[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    sort(arr, n);

    int key = arr[0];

    for(int i=0; i<n; i++) {
        int count = 0,temp;
        for(int j=0; j<n; j++) {
            if(arr[j] == NULL)
                continue;
            if(arr[j] == key) {
                count++;
                arr[j] = NULL;
            } else {
                temp = arr[j];
                break;
            }
        }
        if(count>0)
            cout<<"\n\n"<<key<<"  ->  "<<count;
        key = temp;
    }

    return 0;
}