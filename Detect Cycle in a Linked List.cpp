//Question Link: https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
bool hasCycle(ListNode *head) 
{
	//if empty linked list
	if(head == NULL) return false;
	
	//initialise fast pointer and slow pointers
	ListNode *slow = head, *fast = head;
	
	do{
		//if NULL node exists - marks the end of linked list
		if(fast->next==NULL || fast->next->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);
	
	//Cycle exists
	return true;
}