import java.util.*;
public class median_of_two_sorted_arrays {
    public static void main(String[] args) {
        int[] nums1={1,2};
        int[] nums2={3,4};
        System.out.println(findMedianSortedArrays(nums1,nums2));
    }
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] ans=new int[nums1.length+nums2.length];
        int i=0, j=0, k=0;
        while(i<nums1.length && j<nums2.length){
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                i++;
            }
            else{
                ans[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<nums1.length){
            ans[k]=nums1[i];
            k++;
            i++;
        }
        while(j<nums2.length){
            ans[k]=nums2[j];
            k++;
            j++;
        }
        System.out.println(Arrays.toString(ans));
        if(ans.length%2==0){
            // int s=;
            return (double)(ans[ans.length/2]+ans[(ans.length/2)-1])/2;
        }
        else{
            return (double)ans[ans.length/2];
        }
    }
}
