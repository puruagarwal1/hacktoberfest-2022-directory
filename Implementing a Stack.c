#include<stdio.h>
#include<stdlib.h>
 
#define Size 4 
 
int Top=-1;
int inp_array[Size];

void Push();
 
int main()
{
	int choice;
	
	while(1)	
	{
		printf("\nOperations performed by Stack");
		printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: Push();
					break;
			case 2: Pop();
					break;
			case 3: show();
					break;
			case 4: exit(0);
			
			default: printf("\nInvalid choice!!");
		}
	}
}

// Function to push an element into a Stack
void Push()
{
	int x;
	
	if(Top==Size-1)
	{
		printf("\nStack Overflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack:");
		scanf("%d",&x);
		inp_array[Top + 1]=x
		Top=Top+1;
	}
}

// Function to pop an element from Stack
void Pop()
{
	if(Top==-1)
	{
		printf("\nStack Underflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",inp_array[Top]);
		Top=Top-1;
	}
}
 
 // Function to print all elements present in the Stack
void show()
{
	
	
	if(Top==-1)
	{
		printf("\nStack Underflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",inp_array[i]);
	}
}
