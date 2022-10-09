
// Linear Search is defined as a sequential search algorithm that starts 
// at one end and goes through each element of a list until the desired element 
// is found, otherwise the search continues till the end of the data set.

// For Example  :  array = [ 1,2,3,4,0]  and Element to be found : 0  
// Output  : 4


function search(arr, n, x)
{
    let i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
 
 
    let arr = [ 2, 3, 4, 10, 40 ];
    let x = 10;
    let n = arr.length;
 
    
    let result = search(arr, n, x);
    result === -1 ? console.log("Element is  not present in array") :console.log("Element is present at index " + result);
   