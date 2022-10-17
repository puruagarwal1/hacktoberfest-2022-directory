#include <iostream>
#include <conio.h>
using namespace std;

float FindRoot(int num) {
    int start=0, end=num;
    int mid = (start + ((end-start)/2));
    float ans=0;
    
    while(start <= end) {
        long long int square = (mid*mid);

        if(square == num) {
            return mid;
        } else if(square > num) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }

        mid = (start + ((end-start)/2));
    }

    // Time consuming logic
    /*while((ans*ans) <= num) {
        ans += 0.01;
    }*/

    float factor = 1;
    for(int i=0; i<5; i++) {
        factor = factor / 10;       // To acess 0.1 , 0.01 , 0.001 ....... and so on till 5 places

        for(float j = ans; (j*j) < num; j = j + factor) {
            ans = j;
        }
    }

    return ans;
}

int main() {
    int arr[100], n, p;

    cout<<"Enter the number: ";
    cin>>n;

    cout<<"\nSquare root of "<<n<<" is "<<FindRoot(n);

    return 0;
}