
// BINARY SEARCH 101 in C++ [ The only guide you will need to start with binary search ]
// DISCLAIMER: Mugging up the code won't help you in long run. To tackle tricky problems conceptual knowledge is must. Hence read the comments[concept] carefully.
#include<iostream>
using namespace std;
// Let's say we are given a sorted array of integers
// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// Why do we need Binary Search in the first place?
// Binary Search is a search algorithm that finds the position of a target value within a sorted array.
// But can't we use linear search for this?

int getTargetIndexUsingLinearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1; // If target is not found
}
// Time Complexity of Linear Search is O(n) where n is the size of the array
// Linear search is not efficient for large arrays.

// Notice the inefficiency here in the above code. We are not leveraging the fact that the array is sorted.
// In sorted array we can stand at a index(say middle) and check whether our desired target lies in rightside or leftside of the middle index.
// If it lies in rightside then we can discard the leftside of the array and search in the rightside.
// If it lies in leftside then we can discard the rightside of the array and search in the leftside.
// This is the idea behind Binary Search.
// At every step we are discarding half of the array and searching in the other half.
// n -> n/2 -> n/4 -> n/8 ...... -> 1. Let k be the number of steps to go from n->1 then n/2^k = 1. So, n = 2^k. So, k = log2(n).
//  the number of steps is log2(n) or more specifically log2(range)

// Enough of text, Let's visualize the algorithm now https://assets.leetcode.com/static_assets/posts/1EYkSkQaoduFBhpCVx7nyEA.gif  gif credit: AminiCK

// Let's implement Binary Search in C++
 int getTargetIndexUsingBinarySearch(int arr[],int size,int target) {
    int low = 0, high = size-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)		// target found
			return mid;
		else if (arr[mid] < target)	// Go right
			low = mid + 1;
		else if (arr[mid] > target)	// Go left
			high = mid - 1;
    }
    return -1;
 };

  int getTargetIndexUsingBinarySearch2(int arr[],int size,int target) {
    int low=0,high=size;
    while(low<high){
        int mid=(low+high)>>1; 
        if(arr[mid]==target)return mid; 
        else if(arr[mid]>target){
            high=mid; 
        }else{
            low=mid+1; 
        } 
     }
     return -1; 
 };
 // We are not done yet :). The main show begins now !

 /* 
    Notice the above 2 ways of writing binary search code. There are main 2 differences
    1) Search space which is defined as [low,high] range.
    In the first one search space is [0,size-1] and in the second one search space is [0,size].
    In the first one search space is all the values answer can take.
    In the second one search space is all the values answer can take except size, we consider size also to avoid infinite loop.

    2) The way mid is calculated.
    In the first one mid is calculated as low + (high - low) / 2 and in the second one mid is calculated as (low+high)>>1.
    We are doing this to avoid infinte loop and overflow in case of large values of low and high.
 */

 // Binary search problems can get heavily complex, and without consistent rules, it's very hard to write predictable code. 
 

/* Problems one gets into while implementing binary search
    1. Infinity loop
    2. Can't decide where to shrink
    3. When to exit the loop
*/

/*
 Different way to calculate mid; 
    1. mid = (low + high) / 2;
    2. mid = low + (high - low) / 2;
    3. mid = low + (high - low+1) / 2 ;
    4. mid = low + ((high - low) >> 1);
    5. mid = (low + high) >> 1;

    The disadvantage of 1 is that it may cause overflow, because (low + high) may be larger than the maximum value of int.
    RED ALERT: Don't just blindly use any way to calculate mid, choose mid according to how you are writing while condition 
    i.e whether while(low<high) or while(low<=high); 

    Consider the following example:
    int low=0,high=size-1; 
    while(low<=high){
        int mid = low + ((high - low) / 2); 
        if (target < arr[mid]) {
            hi = mid - 1
        } else {
            lo = mid; 
        }The only guide you will need to start with binary search
    }
    consider int arr[]={1,2} and target=3; 
    here low=0,high=1; 
    mid = low + ((high - low) / 2); => mid=1; 
    Now control falls into else block making low=0 again and it keeps spinning in an infinite loop.

    Takeaway: Always think of a case where only 2 elements are present to check if your code falls into infinite loop or not 
*/

// Now it should not take much effort to write recursive binary search code
// Recursive Binary Search C++
int getTargetIndexUsingRecursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
 
        // If the middle element is the target itself
        if (arr[mid] == target)
            return mid;
 
        // If element is smaller than middle element, then search in left subarray
        if (arr[mid] > target)
            return getTargetIndexUsingRecursiveBinarySearch(arr, low, mid - 1, target);
 
        // else search in right subarray
        return getTargetIndexUsingRecursiveBinarySearch(arr, mid + 1, high, target);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

// If these things are taken care of then you will float in sea of [AC]s  :D

/*
General Tips: 
1. Always follow one search space notation either [0,size-1] or [0,size]
2. Make sure that all possible answers are present in your search space
   For example: Consider a problem where you need to find an index to insert a element in a sorted array so that after insertion the array remains sorted
   In this case in the low=0,high=size-1 convention the search space now becomes low=0, high=size as the element can be inserted at the last index too 
                in the low=0, high=size convention the search space now becomes low=0, high=size+1. 
3. Don't overflow the mid calculation
4. Avoid infinity loop by picking the correct mid and shrinking logic
5. Always think of the case when there are 2 elements left
*/

// In the end, I would say everybody has their own style of binary search, find the style that works for you!

/*
Now it would be a good idea to solve some problems using binary search https://leetcode.com/discuss/study-guide/2452472/Binary-Search-Problem-Types
*/

// HAPPY CODING... !!!

