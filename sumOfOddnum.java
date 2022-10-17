

import java.util.Scanner;

public class sumOfOddnum {
    
    public static int odd_num_gen(int n){
        int var = 0;
        for(int i=1;i<=n;i++){
           if (i%2 !=0){
             var = var+i;
           } 
        }return(var);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the range of odd numbers: ");
        int x = sc.nextInt();
        int sum = odd_num_gen(x);
        System.out.print("sum of the odd numbers are: "+ sum);
    }
}
