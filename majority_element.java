public class majority_element {
    public int majorityElement(int[] nums) {
        int n=nums[0];
        int i,c=1;
        for(i=1;i<nums.length;i++){
            if(c==0){
                n=nums[i];
                c++;
            }
            else if(nums[i]==n)
                c++;
            else
                c--;
        }
        return n;
    }
}
