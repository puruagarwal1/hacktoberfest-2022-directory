#include<stdio.h>

int main()
{
    float mat,phy,che,cf;
    printf("Enter your Maths mark: ");
    scanf("%f",&mat);
    printf("Enter your Physics mark: ");
    scanf("%f",&phy);
    printf("Enter your Chemistry mark: ");
    scanf("%f",&che);
    cf=mat+(phy+che)/2;
    printf("Your Cutoff: %0.2f",cf);
    return 0;
}
