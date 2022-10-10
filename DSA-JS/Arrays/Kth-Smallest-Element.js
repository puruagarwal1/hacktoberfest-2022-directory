// Given an Array Find kth Smallest Element in the Array


// time Complexity  : o(n log(n))
function KthSmallestElement(array,k){
    // Time Complexity of array.sort()  is O(n log(n))

    let sorted  = array.sort((a,b) => a-b)
    console.log(sorted[k-1]);

}

KthSmallestElement([1,5,2,0,8,9,3,6,12],4)

