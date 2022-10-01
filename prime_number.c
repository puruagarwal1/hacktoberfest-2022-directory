#include<stdio.h>
int main()
{
   int x,i,c=0;
   printf("enter the number: ");
   scanf("%d",&x);

   for(i=1;i<=x;i++)
   {
      if(x%i==0)
      {
         c++;
      }
   }

   if(c==2)
   {
      printf("its a prime number");
   }
   else{
      printf("its not a prime number");
   }
   return 0; 
}