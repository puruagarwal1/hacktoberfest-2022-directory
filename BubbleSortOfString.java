import java.io.*;
class BubbleSortOfString
{
    public static void main(String args[]) throws IOException
    {
        System.out.println("Sorting of Strings");
        System.out.println("******************");
        System.out.println("");
        InputStreamReader isr=new InputStreamReader(System.in);
        BufferedReader br=new BufferedReader(isr);
        String nm[] = new String[10];
        int i,j;
        String t="";
        System.out.println("Enter Strings : ");
        for(i=0;i<10;i=i+1)
        {
            nm[i] = br.readLine();
        }
        for(i=0;i<9;i=i+1)
        {
            for(j=(i+1);j<10;j++)
            {
                if(nm[i].compareTo(nm[j])>0)
                {
                    t=nm[i];
                    nm[i]=nm[j];
                    nm[j]=t;
                }
            }
        }
    }
}
            