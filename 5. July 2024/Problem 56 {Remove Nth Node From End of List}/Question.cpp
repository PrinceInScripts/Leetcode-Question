

/*
# 19. Remove Nth Node From End of List
*/
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len==n){
            head=head->next;
            return head;
        }
        int idx=len-n+1;
        temp=head;
        for(int i=1;i<idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
   
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(3);
    // ListNode* c=new ListNode(4);
    // ListNode* d=new ListNode(7);
    // ListNode* e=new ListNode(1);
    // ListNode* f=new ListNode(2);
    // ListNode* g=new ListNode(6);
    a->next=b;
    // b->next=c;
    // c->next=d;
    // d->next=e;
    // e->next=f;
    // f->next=g;
    display(a);

    Solution s1;
    ListNode* ans=s1.removeNthFromEnd(a,1);
    display(a);
    // cout<<ans;
 

    
    
}
