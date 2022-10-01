import java.util.Arrays;

public class SearchIn2DArray {
    public static void main(String[] args) {
        int[][] arr = {
            {1, 2, 3},
            {4, 5, 6, 13},
            {7, 8, 9},
            {10, 11, 12}
        };
        int[] ans = searchIn2DArray(arr, 17);
        System.out.println(Arrays.toString(ans));
    }

    static int[] searchIn2DArray(int[][] arr, int e) {
        int i, j;
        for(i = 0; i < arr.length; i++) {
            for(j = 0; j < arr[i].length; j++) {
                if(arr[i][j] == e) {
                    return  new int[]{i, j};
                }
            }
        }
        return new int[]{-1, -1};

    }
    
}
