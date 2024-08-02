


/*
# 61. Rotate List
*/
/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
   ListNode* rotateRight(ListNode* head, int k) {
     if(head==NULL || head->next==NULL) return head;
       ListNode* a;
       ListNode* b;
       int len=0;
       ListNode* temp=head;
       while(temp!=NULL){
          len++;
          temp=temp->next;
       }

       if(k>len) k=k%len;
       for(int i=0;i<k;i++){
           temp=head;
          while(temp->next->next!=NULL){
             temp=temp->next;
          }
          a=temp;
          b=temp->next;
          cout<<a->val<<endl;
          cout<<b->val<<endl;

          a->next=NULL;
          b->next=head;
          head=b;
          display(head);
       }

       return head;
       
    }
   
    
};

int main(){
    ListNode* a=new ListNode(0);
    ListNode* b=new ListNode(1);
    ListNode* c=new ListNode(2);
    // ListNode* d=new ListNode(4);
    // ListNode* e=new ListNode(5);

 

   a->next=b;
   b->next=c;
//    c->next=d;
//    d->next=e;


    display(a);

    Solution s1;
    ListNode* ans=s1.rotateRight(a,4);
    display(ans);
 

    
    
}
