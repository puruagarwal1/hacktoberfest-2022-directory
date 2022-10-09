#include <bits/stdc++.h>
using namespace std;

int countPrime(int n) {
    vector<bool> prime(n+1, true);
    int count = 0;

    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++) {
        if(prime[i]) {
            count++;

            // Cancelling out all the element present in the table of 'i'
            for(int j=2*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Total count of prime numbers till "<<n<<" is ->  "<<countPrime(n);

    return 0;
}