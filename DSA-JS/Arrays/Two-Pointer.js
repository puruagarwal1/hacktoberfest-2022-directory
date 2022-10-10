// Move All Negative to Left and Positive Elements to Right 


function TwoPointerApproach(array){

    let left = 0;
    let right = array.length -1;
    let temp =0
    while( left <=right){
        
        if(array[left] < 0 && array[right]<0 ){
            left+=1;
        }else if( array[left] >0  && array[right] <0){
            temp = array[left]
            array[left] = array[right]
            array[right] = temp;

            left+=1
            right-=1
        }else if( array[left] >0 && array[right] >0){
            right-=1
        }else{
            left+=1;
            right+=1;
        }
    }
    return array;
}

console.log(TwoPointerApproach([-1,2,-4,9,89,-8,4,-2,1]));