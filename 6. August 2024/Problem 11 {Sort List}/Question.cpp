


/*
# 148. Sort Lists
*/
/*
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/


#include<iostream>
#include<unordered_set>
#include<vector>
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
   ListNode* merge(ListNode* a,ListNode* b){
      ListNode* c=new ListNode(10);
      ListNode* temp=c;

      while(a!=NULL && b!=NULL){
         if(a->val<=b->val){
             temp->next=a;
             temp=temp->next;
             a=a->next;
         } else {
            temp->next=b;
            temp=temp->next;
            b=b->next;
         }
      }

      if(a==NULL) temp->next=b;
      else temp->next=a;

      return c->next;
   }
  ListNode* sortList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
       ListNode* fast=head;
       ListNode* slow=head;

       if(head->next==NULL) return head;

       while(fast->next!=NULL && fast->next->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
       }

       ListNode* a=head;
       ListNode* b=slow->next;

      slow->next=NULL;

       a=sortList(a);
       b=sortList(b);
       return merge(a,b);
    }
 
    
};

int main(){
    ListNode* a1=new ListNode(4);
    ListNode* b1=new ListNode(2);
    ListNode* c1=new ListNode(1);
    ListNode* d1=new ListNode(3);

   

   a1->next=b1;
   b1->next=c1;
   c1->next=d1;

  
   


    display(a1);
   

    Solution s1;
    ListNode* ans=s1.sortList(a1);
    display(ans);
 

    
    
}
