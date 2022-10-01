#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head;
struct node * temp;
struct node * newnode;

void reverse(){
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
        
    }
    
}

int main(){
    int choice = 1;
    head = NULL;
    while(choice == 1){
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->next = NULL;
        int x = 0;
        printf("Enter data into the linked list \n");
        scanf("%d", &x);
        newnode->data = x;
        if(head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
        }
        printf("Do you want to continue? (1/0) \n");
        scanf("%d", &choice);
    }
    temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    reverse();
}
/*

            34
           /  \
          23  56
         /  \   \
        78  21   22

        Inorder Traversal : 
        78 23 21 34 56 22
        Postorder Traversal :
        78 21 23 22 56 34
        Preorder Traversal :
        34 23 78 21 56 22


        */