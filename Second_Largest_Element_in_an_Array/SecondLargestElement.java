import java.util.Arrays;

public class SecondLargestElement{


    static void print2Largest(int[] arr)
    {
        int i, first, second;

        // There should be at least two elements
        if (arr.length < 2)
        {
            System.out.println(" Invalid Input ");
            return;
        }

        // Sort the array
        Arrays.sort(arr);

        // Start from second last element as the largest element is at last
        for (i = arr.length - 2; i >= 0; i--)
        {
            // If the element is not equal to the largest element
            if (arr[i] != arr[arr.length - 1])
            {
                System.out.println("The second largest element is " + arr[i]);
                return;
            }
        }

        System.out.println("There is no second largest element");
    }

    //Code to Execute
    public static void main(String[] args)
    {
        int[] arr = {36, 12, 35, 1, 10, 34, 1, 36};
        print2Largest(arr);
    }
}

// This code is contributed by @parvezi123