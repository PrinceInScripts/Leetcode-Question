


/*
# 206. Reverse Linked List
*/
/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
   ListNode* getNodeIdx(ListNode* head,int n){
      ListNode* temp=head;
      for(int i=0;i<n;i++){
        temp=temp->next;
      }
      return temp;
   }
   ListNode* reverseList1(ListNode* head) {
       ListNode* temp=head;
       int n=0;
       while(temp!=NULL){
        n++;
         temp=temp->next;
       }

      int i=0;
      int j=n-1;
      while(i<j){
        ListNode* left=getNodeIdx(head,i);
        ListNode* right=getNodeIdx(head,j);
        int t=left->val;
        left->val=right->val;
        right->val=t;
        i++;
        j--;
      }

      return head;

        
    }

   ListNode* reverseList2(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
       ListNode* Prev=NULL;
       ListNode* Curr=head;
       ListNode* Next=Curr->next;

       while(Next!=NULL){
         ListNode* t=Next->next;
          Next->next=Curr;
          Prev=Curr;
          Curr=Next;
          Next=t;
       }
       head->next=NULL;

       return Curr;
    }
   ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
       ListNode* Prev=NULL;
       ListNode* Curr=head;
       ListNode* Next;

       while(Curr!=NULL){
          Next=Curr->next;
          Curr->next=Prev;
          Prev=Curr;
          Curr=Next;
       }

       return Prev;
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(4);
    ListNode* e=new ListNode(5);

   

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;

  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.reverseList(a);
    display(ans);
 

    
    
}
