// Find Intersection of Two Array



function IntersectionOfArray(arrayOne , arrayTwo){

    let m = arrayOne.length;
    let n = arrayTwo.length;
    
    let  i=0;
    let j=0;
    let intersection = [];

    while(i<m && j<n){

        if(arrayOne[i] < arrayTwo[j]){
            i++
        }else if( arrayOne[i] > arrayTwo[j]){
            j++
        }else{
            intersection.push(arrayOne[i])
            i++
            j++
        }
    }

    return intersection;
}


console.log(IntersectionOfArray([1,2,3,4],[3,4,5,6]));