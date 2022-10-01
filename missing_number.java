import java.util.*;
public class missing_number {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        return number(nums, 0);
    }
    public int number(int[] nums, int i){
        if(i==nums.length){
            return i;
        }
        if(nums[i]!=i){
            return i;
        }
        return number(nums, i+1);
    }
}
