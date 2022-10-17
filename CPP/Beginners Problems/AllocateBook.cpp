#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
    int count = 1, pagesum = 0;

    for(int i=0; i<n; i++) {
        if(pagesum + arr[i] <= mid) {
            pagesum += arr[i];
        } else {
            count++;
            if(count > m ||  arr[i] > mid) {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}

int FindMinimumPages(int arr[], int n, int m) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int start = 0, end = sum;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start < end) {
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid;
        } else {
            start = mid + 1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
}

int main() {
    int arr[100], n, m;

    cout<<"Enter the size of the array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the number of students: ";
    cin>>m;

    int ans = FindMinimumPages(arr, n, m);

    cout<<"Required no of pages is: "<<ans;

    return 0;
}