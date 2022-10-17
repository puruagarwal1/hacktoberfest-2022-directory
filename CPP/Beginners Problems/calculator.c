#include <stdio.h>

int main() {

    int key;

    printf("\n\n-------------------------------------------------------------------\n");
    printf("                         MINI PROJECT - CALCULATOR");
    printf("\n-------------------------------------------------------------------\n");
    printf("Enter your choice : \n");
    printf("\t1  ->  Go to Calculator\n\t2  ->  Exit\n");
    scanf("%d", &key);
    
    while(key == 1) {
        int op;
        int first, second;

        printf("Enter your choice for calculation : \n");
        printf("\t1  ->  Addition\n\t2  ->  Subtraction\n\t3  ->  Multiplication\n\t4  ->  Division\n");
        scanf("%d", &op);

        if(op<1 || op>4) {
            printf("Error! You have entered wrong option. Try again!");
            goto NEW;
        }

        printf("Enter two operands: ");
        scanf("%d %d", &first, &second);

        switch (op) {
            case 1:
                printf("Sum = %d", first+second);
                break;
            case 2:
                printf("Difference = %d", first-second);
                break;
            case 3:
                printf("Product = %d", first*second);
                break;
            case 4:
                printf("Quoitent = %d and remainder = %d", first/second, first%second);
                break;
        }

        NEW:

        printf("\n\n-------------------------------------------------------------------\n");
        printf("                         MINI PROJECT - CALCULATOR");
        printf("\n-------------------------------------------------------------------\n");
        printf("Enter your choice : \n");
        printf("\t1  ->  Continue\n\t2  ->  Exit\n");
        scanf("%d", &key);
    }

    printf("\n\n-------------------------------------------------------------------\n");
    printf("                           THANK YOU :))\n");
    printf("-------------------------------------------------------------------\n");

    return 0;
}