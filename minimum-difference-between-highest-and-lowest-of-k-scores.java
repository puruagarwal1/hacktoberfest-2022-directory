import java.util.*;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int sm = Integer.MAX_VALUE;
        if (nums.length < 2)
            return 0;
        else {
            int b = k;
            for (int i = 0; b <= nums.length; i++) {
                int t = nums[b - 1] - nums[i];
                b++;
                if (t < sm)
                    sm = t;
            }
        }
        return sm;
    }
}
