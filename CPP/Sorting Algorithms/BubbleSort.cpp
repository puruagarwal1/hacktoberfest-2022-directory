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

void SortDescending(int arr[], int size) {

    for(int i=0; i<size; i++) {

        for(int j=size-1; j>0; j--) {

            if(arr[j] > arr[j-1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }

        }

    }

}

int main() {
    int arr[100], n;
    char ch;
    cout<<"\nEnter the size of array: ";
    cin>>n;

    cout<<"\nEnter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nEnter your choice: ";
    cout<<"\n\n\tPress  'A'  for sorting the array in ascending order";
    cout<<"\n\tPress  'D'  for sorting the array in descending order\n";
    cin>>ch;

    if(ch == 'A' || ch == 'a')
        SortAscending(arr, n);
    else if(ch == 'D' || ch == 'd')
        SortDescending(arr, n);
    else
        cout<<"You have entered wrong input. Thanks!";

    cout<<"\n\nThe sorted array is: ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<"  ";
    }

    return 0;
}