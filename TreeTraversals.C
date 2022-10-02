#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create(){
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value in the node\nEnter -1 to skip\n");
    int value = 0;
    scanf("%d", &value);
    if(value == -1){
        return NULL;
    }
    else{
        newnode->data = value;
        printf("Enter left child of the node\n");
        newnode->left = create();
        printf("Enter right child of the node\n");
        newnode->right = create();
        return newnode;
    }

};

void inorder(struct node * root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node * root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left); 
    preorder(root->right);
}

void postorder(struct node * root){
    if(root == NULL) return;
    postorder(root->left); 
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct node * root;
    root = NULL;
    root = create();
    printf("Inorder Traversal : \n");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal : \n");
    postorder(root);
    printf("\n");
    printf("Preorder Traversal : \n");
    preorder(root);
    printf("\n");

    return 0;
}