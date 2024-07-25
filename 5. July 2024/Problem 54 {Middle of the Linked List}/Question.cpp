

/*
# 876.Middle of the Linked List
*/
/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
 
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
    ListNode* middleNode1(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        for(int i=1;i<=len/2;i++){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* middleNode2(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        int midIdx=len/2;
        ListNode* mid=head;
        for(int i=1;i<=midIdx;i++){
            mid=mid->next;
        }
        return mid;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(4);
    // ListNode* e=new ListNode(5);
    a->next=b;
    b->next=c;
    c->next=d;
    // d->next=e;
    display(a);

    Solution s1;
    ListNode* ans=s1.middleNode(a);
    display(a);
    cout<<ans->val;
 

    
    
}
