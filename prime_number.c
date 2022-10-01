#include <stdio.h>
int main()
{
   int num, isPrime = 1;
   printf("Enter the number: ");
   scanf("%d", &num);

   for (int i = 2; i * i <= num; i++)
   {
      if (num % i == 0)
      {
         isPrime = 0;
         break;
      }
   }

   if (isPrime == 1 && num != 1)
   {
      printf("%d is a prime number.", num);
   }
   else
   {
      printf("%d is not a prime number.", num);
   }
   return 0;
}