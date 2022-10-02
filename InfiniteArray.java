//https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
public class InfiniteArray {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30, 31, 32, 33, 34, 35};
        int target = 15;
        System.out.println(answer(arr, target));

    }

    public static int answer(int[] arr, int target) {
        int start = 0;
        int end = 1;
        while(target > arr[end]) {
            int temp = end+1;
            end = end + (end - start + 1) * 2;
            start = temp;
        }
        return binarySearch(arr, target, start, end);


    }

    public static int binarySearch(int[] arr, int target, int start, int end) {
        while(start<= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] == target) {
                return mid;
            }else if(arr[mid] > target) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return -1;
    }
    
}
