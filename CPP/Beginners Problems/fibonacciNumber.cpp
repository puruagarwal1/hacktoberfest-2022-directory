#include <iostream>
using namespace std;

int fibonacciNumber(int n) {
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fibonacciNumber(n-1) + fibonacciNumber(n-2);
}

int main() {
    int n;
    cin>>n;

    // Calculating nth fibonacci number
    cout<<fibonacciNumber(n)<<"\n";

    // Printing fibonacci series
    for(int i=1; i<=n; i++)
        cout<<fibonacciNumber(i)<<" ";
    return 0;
}