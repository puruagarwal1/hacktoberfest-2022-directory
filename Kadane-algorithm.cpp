#include<bits/stdc++.h>
using namespace std;

int kodane(vector<int> arr){
    int max_subArray_sum = 0;
    int currentSubArraySum = 0;

    for(int i = 0; i < arr.size(); i++){
        currentSubArraySum = currentSubArraySum + arr[i];
        if(currentSubArraySum > max_subArray_sum)
            max_subArray_sum = currentSubArraySum;
        if(currentSubArraySum < 0)
            currentSubArraySum = 0;
    }
    return max_subArray_sum;
}

int main(){
    int n;
    vector<int> arr;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout<<"Largest subarray sum in inputted array = " << kodane(arr); 
}

/*
Example Test cases

5
1 2 3 4 5
output: 15

5
3 1 -5 2 3
output: 5
*/