#include <bits/stdc++.h>
using namespace std;

int calculateGCD(int num1, int num2) {
    if(num1 == 0)
        return num2;
    if(num2 == 0)
        return num1;

    while(num1 != num2) {
        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }

    return num1;
}

int main() {
    int n, m;
    cout<<"Enter the two numbers : ";
    cin>>n>>m;

    cout<<"GCD of "<<n<<" and "<<m<<" is ->  "<<calculateGCD(n, m);

    return 0;
}