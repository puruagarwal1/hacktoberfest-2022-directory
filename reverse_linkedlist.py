class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
 
class LinkedList:
    def __init__(self):
        self.head = None

    def reverse(self):
        prev = None
        current = self.head
        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
 
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
 
    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next
 
 
# Driver code
l = LinkedList()
l.push(25)
l.push(9)
l.push(96)
l.push(75)
 
l.reverse()
print("\nReversed Linked List")
l.printList()