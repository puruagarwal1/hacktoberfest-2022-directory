#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int a;
    struct node *left;
    struct node *right;
};
 
void generate(struct node **, int);
void infix(struct node *);
void postfix(struct node *);
void prefix(struct node *);
void delete(struct node **);
 
int main()
{
    struct node *head = NULL;
    int choice = 0, num, flag = 0, key;
 
    do
    {
        printf("\nEnter your choice:\n1. Insert\n2. Traverse via infix\n3.Traverse via prefix\n4. Traverse via postfix\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: 
            printf("Enter element to insert: ");
            scanf("%d", &num);
            generate(&head, num);
            break;
        case 2: 
            infix(head);
            break;
        case 3: 
            prefix(head);
            break;
        case 4: 
            postfix(head);
            break;
        case 5: 
            delete(&head);
            printf("Memory Cleared\nPROGRAM TERMINATED\n");
            break;
        default: printf("Not a valid input, try again\n");
        }
    } while (choice != 5);
    return 0;
}
 
void generate(struct node **head, int num)
{
    struct node *temp = *head, *prev = *head;
 
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->a = num;
        (*head)->left = (*head)->right = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (num > temp->a)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (struct node *)malloc(sizeof(struct node));
        temp->a = num;
        if (num >= prev->a)
        {
            prev->right = temp;
        }
        else
        {
            prev->left = temp;
        }
    }
}
 
void infix(struct node *head)
{
    if (head)
    {
        infix(head->left);
        printf("%d   ", head->a);
        infix(head->right);
    }
}
 
void prefix(struct node *head)
{
    if (head)
    {
        printf("%d   ", head->a);
        prefix(head->left);
        prefix(head->right);
    }
}
 
void postfix(struct node *head)
{
    if (head)
    {
        postfix(head->left);
        postfix(head->right);
        printf("%d   ", head->a);
    }
}
 
void delete(struct node **head)
{
    if (*head != NULL)
    {
        if ((*head)->left)
        {
            delete(&(*head)->left);
        }
        if ((*head)->right)
        {
            delete(&(*head)->right);
        }
        free(*head);
    }
}