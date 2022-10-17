function binarySearch(arr, l, r, x){
    if (r >= l) {
        let mid = l + Math.floor((r - l) / 2);
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
 
let arr = [ 1, 2, 4, 14, 40 ];
let x = 14;
let n = arr.length
let result = binarySearch(arr, 0, n - 1, x);
result === -1 ? console.log("Element is  not present in array") :console.log("Element is present at index " + result);
