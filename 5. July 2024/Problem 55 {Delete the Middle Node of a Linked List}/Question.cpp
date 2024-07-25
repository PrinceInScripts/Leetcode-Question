

/*
# 2095.Delete the Middle Node of a Linked List
*/
/*
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105

 
*/


#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* deleteMiddle1(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==1){
            head=NULL;
            return head;
        }
        int midIdx=len/2;
        temp=head;
        for(int i=1;i<=midIdx-1;i++){
             temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(fast->next==NULL) head=NULL; 
        else if(fast->next->next==NULL) slow->next=NULL;
        else { 
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->val=slow->next->val;
        slow->next=slow->next->next;
        }
        return head;
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(3);
    ListNode* c=new ListNode(4);
    ListNode* d=new ListNode(7);
    ListNode* e=new ListNode(1);
    ListNode* f=new ListNode(2);
    ListNode* g=new ListNode(6);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    display(a);

    Solution s1;
    ListNode* ans=s1.deleteMiddle(a);
    display(a);
    // cout<<ans;
 

    
    
}
