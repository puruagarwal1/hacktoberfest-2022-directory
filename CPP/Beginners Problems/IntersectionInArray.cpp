#include <iostream>
#include <limits.h>

using namespace std;

void CheckIntersection(int arr1[], int arr2[], int n1, int n2) {
    for(int i=0; i<n1; i++) {

        if(arr1[i] == INT_MIN) {
            continue;
        }

        for(int j=0; j<n2; j++) {
            if(arr1[i] == arr2[j]) {
                cout<<"  "<<arr1[i];
                arr1[i] = INT_MIN;
                arr2[j] = INT_MIN;
            }
        }

    }
}

int main() {
    int arr1[100], arr2[100], n1, n2;
    cout<<"\nEnter the size of both arrays: ";
    cin>>n1>>n2;

    cout<<"\nEnter the elements of first array: ";
    for(int i=0; i<n1; i++) {
        cin>>arr1[i];
    }

    cout<<"\nEnter the elements of second array: ";
    for(int i=0; i<n2; i++) {
        cin>>arr2[i];
    }

    CheckIntersection(arr1, arr2, n1, n2);

    return 0;
}