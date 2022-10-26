public class FindPeakElement {
    static int findElement(int[] arr) {
        int n = arr.length;
//        int ans = 0;

        if(n==1)
            return 0;
        if(arr[0]>=arr[1])
            return 0;
        if(arr[n-1]>=arr[n-2])
            return n-1;

        for(int i = 1; i <n; i++)
            if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
                return i;

        return 0;
    }

    public static void main(String[] args) {
        int[] nums = {12,13,4,16,11};

        System.out.println("The peak element is :" + findElement(nums));
    }
}
