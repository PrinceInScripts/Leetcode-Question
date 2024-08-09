


/*
# 1721. Swapping Nodes in a Linked List
*/
/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100

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
    
     ListNode* swapNodes1(ListNode* head, int k) {
       ListNode* temp=head;
       int n=0;
       while(temp){
        n++;
        temp=temp->next;
       }

       int p=n-k+1;
       temp=head;
       int idx=1;
       ListNode* a;
       ListNode* b;
       while(temp){
            if(idx==k) a=temp;
            if(idx==p) b=temp;
            temp=temp->next;
            idx++;
       }
       int t=a->val;
       a->val=b->val;
       b->val=t;

       return head;

    }
     ListNode* swapNodes(ListNode* head, int k) {
       ListNode* first=head;
       ListNode* second=head;
       ListNode* temp=head;

       for(int i=1;i<k;i++){
         first=first->next;
       }

       temp=first;
       while(temp->next){
          temp=temp->next;
          second=second->next;
       }

       int t=first->val;
       first->val=second->val;
       second->val=t;

       return head;
      

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
    ListNode* ans=s1.swapNodes(a,2);
    display(ans);
    
 

    
    
}
