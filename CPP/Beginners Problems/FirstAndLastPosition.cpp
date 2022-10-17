// Write a program to find the first and last position of an element in an array

#include <iostream>
using namespace std;

int FirstPosition(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(arr[m] == key) {
            ans = m;
            e = m - 1;
        }

        if(arr[m] > key) {
            e = m - 1;
        }

        if(arr[m] < key) {
            s = m + 1;
        }

        m = s + (e-s)/2;
    }

    return ans;

}

int LastPosition(int arr[], int n, int key) {
    int s = 0, e = n-1;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s<=e) {
        if(arr[m] == key) {
            ans = m;
            s = m + 1;
        }

        if(arr[m] > key) {
            e = m - 1;
        }

        if(arr[m] < key) {
            s = m + 1;
        }

        m = s + (e-s)/2;
    }

    return ans;

}

int main() {
    int arr[100], n, key;

    cout<<"\nEnter the size of array: ";
    cin>>n;

    cout<<"\nEnter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nEnter the element : ";
    cin>>key;

    cout<<"\n\n   First Position: "<<FirstPosition(arr, n, key);
    cout<<"\n   Last Position: "<<LastPosition(arr, n, key);

    return 0;
}