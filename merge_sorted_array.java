public class merge_sorted_array {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i;
        for(i=(m+n-1);i>=0;i--){
            if(n-1>=0){
            if(m-1>=0&&nums1[m-1]>nums2[n-1]){
                nums1[i]=nums1[m-1];
                m--;
            }
            else{
                nums1[i]=nums2[n-1];
                n--;
            }
        }
        }
        
    }
}
