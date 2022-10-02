
#include<bits/stdc++.h>
using namespace std; 

/*
    Problem Statement: Given a 2D array, find the maximum sum submatrix in it
    Example:
    Input:  1   2  -1 -4 -20
            -8 -3   4  2  1
            3  8  10  1  3
           -4 -1  1   7  -6
    Output: 29 
    by choosing the following 3x3 submatrix:
            -3  4   2
            8  10  1
            -1  1  7
*/

// DISCLAIMER: Try it on your own first

// HINT:
// Recall Kadane's algorithm for 1D array.
// It is a O(N) algorithm that finds the maximum sum of a contiguous subarray in an array.
int kadane(vector<int> arr){
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

// Solution:  Let's try extending kadane's 1D array idea to 2D array.
// But Kadane's algorithm operates on 1D array, so we need to convert 2D array to 1D array somehow elegantly.
// We can do this by fixing the left and right columns and finding the sum of elements between these two columns for every rows 
// Example:
/*
  let the 2D array be:
  -1 -2 -3
  4   5  6
  7   8  9
-10 -11 -12
 for simplicity lets assume left column is first column and right column is last column
  so the 1D array equivalent to above 2D array is:
  -1-2-3 = -6
  4+5+6 = 15
  7+8+9 = 24
  -10-11-12 = -33
  => 
 -1  -2  -3        -6
  4   5   6  ===   15
  7   8   9        24
 -10 -11 -12      -33
  
  Now we try to apply kadane's algorithm on this 1D array [-6,15,24,-33]
    => kadane([-6,15,24,-33]) = 42
    where we can see that the maximum sum subarray is [15,24]
    that means the maximum sum submatrix is:
    4  5  6
    7  8  9
    which has sum 42 and boundary indications as first column-to-last column, second row-to-third row
*/

// Now we can write the code for the above idea


// Implementation of Kadane's algorithm for 1D array. 
// The function returns the maximum sum and stores starting and ending indexes of the maximum sum subarray 
int ModifiedKadane(vector<int>arr, int& cursumLeft, int& cursumRight, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN;

	// Just some initial value to check
	// for all negative values case
	cursumRight = -1;

	// variable to store starting index of intermediate subarrays
	int local_start = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			cursumLeft = local_start;
			cursumRight = i;
		}
	}

	// There is at-least one  non-negative number
	if (cursumRight != -1)
		return maxSum;

	// Special Case: When all numbers in arr[] are negative
	maxSum = arr[0];
	cursumLeft = cursumRight = 0;

	// Find the maximum negative element in array
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			cursumLeft = cursumRight = i;
		}
	}
	return maxSum;
}


// function which finds maximum sum rectangle in grid[][]
void findMaxSumIn2DMatrix(vector<vector<int>>grid,int rows,int cols)
{
	
	int maxSum = INT_MIN;
	// variables to indicate maximum submatrix boundaries
	int finalLeft, finalRight, finalTop, finalBottom;


	int left, right, i;
	vector<int>temp(rows,0);
	

	// Set the left colsumn
	for (left = 0; left < cols; ++left) {

		// Set the right colsumn for the left
		// colsumn set by outer loop
		for (right = left; right < cols; ++right) {

			// Calculate sum between current left and right for each row
			for (i = 0; i < rows; ++i)
				temp[i] += grid[i][right];

			// Find the maximum sum subarray in this created temp array using Kadane's 1D algorithm.
			// This modifed Kadane function also sets the starting and ending indices of the maximum sum subarray.
			int cursum, cursumLeft, cursumRight;
			cursum = ModifiedKadane(temp, cursumLeft, cursumRight, rows);

			// Compare sum with maximum sum so far.
			// If sum is more, then update maxSum and
			// other output values
			if (cursum > maxSum) {
				maxSum = cursum;
				finalLeft = left;
				finalRight = right;
				finalTop = cursumLeft;
				finalBottom = cursumRight;
			}
		}
	}

	// Printing final values
	cout << "(Top, Left) ("<< finalTop << ", "<< finalLeft<< ")" << endl;
	cout << "(Bottom, Right) ("<< finalBottom << ", "<< finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{   
    int rows,cols; 
    cin>>rows>>cols;
	vector<vector<int>>grid(rows,vector<int>(cols)); 
	for(int i=0;i<rows;++i){
		for(int j=0;j<cols;++j){
			cin>>grid[i][j]; 
		}
	}
	findMaxSumIn2DMatrix(grid,rows,cols);
	return 0;
}



