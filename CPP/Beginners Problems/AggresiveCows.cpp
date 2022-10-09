#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {
    int count = 1, lastpos = arr[0];

    for(int i=0; i<n; i++) {
        if(arr[i] - lastpos <= mid) {
            count++;
            if(count == k)
                return true;
            lastpos = arr[i];
        }
    }
    return false;
}

int FindMaximumDistance(int arr[], int n, int k) {
    int start = 0, ans = -1;

    int end = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i] > end)
            end = arr[i];
    }
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid -1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
}

int main() {
    int arr[100], n, k;

    cout<<"Enter the size of the array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the number of cows: ";
    cin>>k;

    int ans = FindMaximumDistance(arr, n, k);

    cout<<"Required distance is: "<<ans;

    return 0;
}