import java.util.Arrays;
import java.util.Scanner;

class QuickSort {
    static int arr[];

    static int partition(int[] arr, int low, int high)  // creates a partition and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
    {

        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {

            if (arr[j] < pivot) {

                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

    static void quickSort(int[] arr, int lb, int ub)   // function implementing QuickSort algorithm
    {
        if (lb < ub) {
            int x = partition(arr,lb,ub);
            quickSort(arr,lb,x-1);
            quickSort(arr,x+1,ub);
        }
    }

    public static void main(String[] args)    // Main method
    {
       Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int size = sc.nextInt();
        arr = new int[size];
        System.out.println("Enter elements in the array");
        for (int i = 0;i<size;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Array before Sorting :");
        System.out.println(Arrays.toString(arr));
        quickSort(arr, 0, size - 1);
        System.out.println("Array after sorting :");
        System.out.println(Arrays.toString(arr));
    }
}

