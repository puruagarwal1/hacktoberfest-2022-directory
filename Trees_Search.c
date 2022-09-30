#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
	struct node*left;
	struct node*right;
};
typedef struct node BST;
BST *LOC, *PAR;
void search(BST *root, int item)
{
    BST *save,*ptr;
    if (root == NULL)
    {
        LOC = NULL;
        PAR=NULL;
    }
    if (item == root -> info)
    {
    LOC = root;
    PAR = NULL;
    return;
    }
    if (item < root->info)
    {
        save = root;
        ptr = root->left;
    }
    else
    {
        save = root;
        ptr = root -> right;
    }
    while( ptr != NULL)
    {
        if (ptr -> info == item)
        {
            LOC = ptr;
            PAR = save;
            return;
        }
        if(item < ptr->info)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    LOC = NULL;
    PAR = save;
    return;
}
 
struct node* findmin(struct node*r)
{
	if (r == NULL)
		return NULL;
	else if (r->left!=NULL)
		return findmin(r->left);
	else if (r->left == NULL)
		return r;
}
struct node*insert(struct node*r, int x)
{
	if (r == NULL)
	{
            r = (struct node*)malloc(sizeof(struct node));
            r->info = x;
            r->left = r->right = NULL;
            return r;
	}
	else if (x < r->info)
            r->left = insert(r->left, x);
	else if (x > r->info)
            r->right = insert(r->right, x);
	return r;
}
 
struct node* del(struct node*r, int x)
{
	struct node *t;
	if(r == NULL)
		printf("\nElement not found");
	else if (x < r->info)
            r->left = del(r->left, x);
	else if (x > r->info)
            r->right = del(r->right, x);
	else if ((r->left != NULL) && (r->right != NULL))
	{
            t = findmin(r->right);
            r->info = t->info;
            r->right = del(r->right, r->info);
	}
	else
	{
            t = r;
            if (r->left == NULL)
                r = r->right;
            else if (r->right == NULL)
                r = r->left;
            free(t);
	}
	return r;
}
 
 
int main()
{
    struct node* root = NULL;
    int x, c = 1, z;
    int element;
    char ch;
    printf("\nEnter an element: ");
    scanf("%d", &x);
    root = insert(root, x);
    printf("\nDo you want to enter another element :y or n");
    scanf(" %c",&ch);
    while (ch == 'y')
    {
        printf("\nEnter an element:");
        scanf("%d", &x);
        root = insert(root,x);
        printf("\nPress y or n to insert another element: y or n: ");
        scanf(" %c", &ch);
    }
    while(1)
    {
        printf("\n1 Insert an element ");
        printf("\n2 Delete an element");
        printf("\n3 Search for an element ");
        printf("\n4 Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("\nEnter the item:");
                scanf("%d", &z);
                root = insert(root,z);
                break;
            case 2:
                printf("\nEnter the info to be deleted:");
                scanf("%d", &z);
                root = del(root, z);
		break;
            case 3:
                printf("\nEnter element to be searched:  ");
                scanf("%d", &element);
                search(root, element);
                if(LOC != NULL)
                    printf("\n%d Found in Binary Search Tree !!\n",element);
                else
                    printf("\nIt is not present in Binary Search Tree\n");
                break;
            case 4:
                printf("\nExiting...");
		return;
            default:
                printf("Enter a valid choice: ");
 
        }
    }
    return 0;
}