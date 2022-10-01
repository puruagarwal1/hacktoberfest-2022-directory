public class power_of_four {
    public boolean isPowerOfFour(int n) {
        if(n==0 || n==2 || n==3){
            return false;
        }
        else if(n==1){
            return true;
        }
        if(n%4==0){
            return isPowerOfFour(n/4);
        }
        else{
            return false;
        }
    }
}
