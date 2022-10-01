//Floyds Cycle Detection Algorithm
//Using the two pointer approach (Slow and Fast Pointer)

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

//Function to detect if a Cycle is present or not
//Using Slow and Fast Pointers
bool detectLoop(Node *head)
{
    Node *slowPointer = head;
    Node *fastPointer = head;
    
    while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return 1;
        }
 
        return 0;
}
 
int main()
{
    //A Circular Linked List is taken as an example
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next = temp1;
    temp1->next=temp2;
    temp2->next=head;
    
    if(detectLoop(head) == 1)
      cout<<"Cycle is present"<<endl;
    else
       cout<<"Cycle is not present"<<endl;

    return 0;
}