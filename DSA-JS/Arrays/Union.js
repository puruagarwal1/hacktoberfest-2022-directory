// Find Union of Two Sorted Array

function UnionOfArray(arrayOne , arrayTwo){
    let m = arrayOne.length;
    let n = arrayTwo.length;

    let i =0;
    let j =0;

    let union=[];

    while( i<m && j<n){

        if(arrayOne[i] < arrayTwo[j]){
            union.push(arrayOne[i])
            i++
        }else if(arrayOne[i] == arrayTwo[j]){
            union.push(arrayOne[i])
            i++;
            j++;
        }else{
            union.push(arrayTwo[j])
            j++
        }
    }


    while( i< m){
        union.push(arrayOne[i])
        i++
    }
    while(j<n){
        union.push(arrayTwo[j])
        j++
    }

    return union

}


console.log(UnionOfArray([1,2,4,5] , [3,4,6,7]));