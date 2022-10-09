#include <iostream>
using namespace std;

int findduplicate(int arr[], int size) {
    int ans=0;

    for(int i=0; i<size; i++)
        ans = ans ^ arr[i];

    for(int i=1; i<size; i++)
        ans = ans ^ i;
    
    return ans;
}

int main() {
    int arr[100], n;
    cout<<"\nEnter the size of array: ";
    cin>>n;

    cout<<"\nEnter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int ans = findduplicate(arr, n);
    cout<<"\n\nThe duplicate element is: "<<ans;

    return 0;
}