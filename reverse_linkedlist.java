class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { 
        this.val = val; 
        this.next=null;
    }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Main
{
    public ListNode reverseList(ListNode head) {
        ListNode temp,temp1,temp2;
        temp=head;
        if(head==null || head.next==null){
            return head;
        }
        temp1=head.next;
        head.next=null;
        while(temp1.next!=null){
            temp2=temp1.next;
            temp1.next=temp;
            temp=temp1;
            temp1=temp2;
        }
        temp1.next=temp;
        return temp1;

    }
	public static void main(String[] args) {
		ListNode head=new ListNode(25);
        head.next=new ListNode(9);
        ListNode temp=head.next;
        temp.next=new ListNode(96);
        temp=temp.next;
        temp.next=new ListNode(75);
        ListNode temp1=head;
        while(temp1!=null){
            System.out.print(temp1.val+" ");
            temp1=temp1.next;
        }
        System.out.println();
        Main obj=new Main();
        temp1=obj.reverseList(head);
        while(temp1!=null){
            System.out.print(temp1.val+" ");
            temp1=temp1.next;
        }
        
	}
}
