#include<stdio.h>
#include<math.h>

int main()
{
    int x,i, prime = 1;
    printf("enter the number: ");
    scanf("%d",&x);

    // only need to check up to sqrt(x)
    // if a*b = x, a or b cannot be larger than sqrt(x) because sqrt(x) * sqrt(x) = x
    int sqrt_x = sqrt(x);
    for (i=2;i<=sqrt_x;i++)
    {
        if (x%i==0)
        {
            prime = 0;
            break;
        }
    }

    if (prime == 1)
    {
        printf("its a prime number");
    }
    else
    {
        printf("its not a prime number");
    }
    return 0;
}
