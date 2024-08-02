


/*
# 83. Remove Duplicates from Sorted List
*/
/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/


#include<iostream>
#include<unordered_set>
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
    ListNode* deleteDuplicates1(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp=head;

        while(temp->next!=NULL){
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
            } else {
                temp=temp->next;
            }
        }

        return head;
       
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;


        ListNode* a=head;
        ListNode* b=a->next;

        while(b!=NULL){
            while(b!=NULL&& b->val==a->val)
                b=b->next;
            
            a->next=b;
            a=b;
            if(b!=NULL) b=b->next;
        }

        return head;
       
    }
     
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(1);
    ListNode* c=new ListNode(2);
    ListNode* d=new ListNode(3);
    ListNode* e=new ListNode(3);

 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;


    display(a);

    Solution s1;
    ListNode* ans=s1.deleteDuplicates(a);
    display(ans);
 

    
    
}
