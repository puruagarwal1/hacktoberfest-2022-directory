import java.util.Scanner;

class mergesort {
    public static void main(String[] args) {
        // Object Creation
        Scanner sc = new Scanner(System.in);
        mergesort ob = new mergesort();
        // Input
        System.out.print("Enter the number of Integer elements to sort: ");
        int n = sc.nextInt();
        System.out.println("Enter Elements here:");
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        // Calling sort method
        ob.sort(arr, 0, (n - 1));
        // Printing output
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    void sort(int arr[], int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            sort(arr, l, mid);
            sort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    /**
     * It takes an array, a left index, a middle index, and a right index, and merges the two subarrays
     * into one sorted array
     * 
     * @param arr The array to be sorted.
     * @param l left index of the sub-array of arr to be sorted
     * @param mid the middle index of the array
     * @param r the rightmost index of the array
     */
    void merge(int arr[], int l, int mid, int r) {
        int arr1[] = new int[r + 1];
        int i = l;
        int j = mid + 1;
        int k = l;
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                arr1[k] = arr[i];
                i++;
            } else {
                arr1[k] = arr[j];
                j++;
            }
            k++;
        }
        if (i > mid)
            while (j <= r) {
                arr1[k] = arr[j];
                k++;
                j++;
            }
        else if (j > r)
            while (i <= mid) {
                arr1[k] = arr[i];
                k++;
                i++;
            }
        for (k = l; k <= r; k++)
            arr[k] = arr1[k];
    }
}