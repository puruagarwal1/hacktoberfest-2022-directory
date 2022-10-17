#include<iostream>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
/*
    Bubble Sort
    space complexity = O(1)
    time complexity = O(n^2)
    best case = O(n)
    worst case = O(n^2)
*/
void sortBubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
                
        }
        if (swapped == false) break;
    }
}
int main()
{
    int arr[6] = {10, 12, 45, 1, 23, 90};
    sortBubble(arr, 6);
    printArr(arr, 6);
}
