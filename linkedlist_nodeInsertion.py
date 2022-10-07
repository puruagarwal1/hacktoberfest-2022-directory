class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self):
        self.head=None

    def printing(self):
       temp=self.head
       while(temp):
         print(temp.data)
         temp=temp.next

    def push(self,new_data): #to insert new node in the beginning 
        #1. lets create a node with provided Data
        new_node=Node(new_data)
        #2 we have the node now join at beginning 
        #make the next of the node as head 
        new_node.next=self.head
        
        #3 now make the point of this node to first one ,that is new head is our new node
        self.head = new_node

if __name__ == "__main__":
    lst=LinkedList()
    lst.head=Node(1)
    second=Node(2)
    third=Node(4)
    lst.head.next=second
    second.next=third

    #we will use push function to insert node in front
    lst.push(7)
    lst.printing()
