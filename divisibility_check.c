#include <stdio.h>
int main()
{
    int num;
    printf("Type the number you want to check divisibility of: ");
    scanf("%d", &num);

    for (int i = 2; i < 10; i++)
    {
        if (num % i == 0)
        {
            printf("Number is divisible by %d\n", i);
        }
        else
        {
            printf("Number is not divisible by %d\n", i);
        }
    }

    return 0;
}
