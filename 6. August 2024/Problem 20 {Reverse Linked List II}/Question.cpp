


/*
# 92. Reverse Linked List
*/
/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?

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
    
   ListNode* reverse(ListNode* head){
       ListNode* Prev=NULL;
       ListNode* Curr=head;
       ListNode* Next=head;

       while(Curr){
           Next=Curr->next;
           Curr->next=Prev;
           Prev=Curr;
           Curr=Next;
          
       }

       return Prev;
   }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        
        ListNode* temp=head;
        int idx=1;
        while(temp){
            if(idx==left-1) a=temp;
            if(idx==left) b=temp;
            if(idx==right) c=temp;
            if(idx==right+1) d=temp;
            idx++;
            temp=temp->next;
            
        }
        if(a) a->next=NULL;
        c->next=NULL;

        c=reverse(b);
        if(a) a->next=c;
         b->next=d;
       if(a) return head;
       return c;
       

    }
    
};

int main(){
    ListNode* a=new ListNode(10);
    ListNode* b=new ListNode(20);
    ListNode* c=new ListNode(30);
    ListNode* d=new ListNode(40);
    ListNode* e=new ListNode(50);
    ListNode* f=new ListNode(60);
    ListNode* g=new ListNode(70);
    ListNode* h=new ListNode(80);
    ListNode* i=new ListNode(90);
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;
   f->next=g;
   g->next=h;
   h->next=i;

  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.reverseBetween(a,3,5);
    display(ans);
    
 

    
    
}
