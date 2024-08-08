


/*
# 328. Odd Even Linked List
*/
/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

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
     ListNode* oddEvenList(ListNode* head) {
       ListNode* a=new ListNode(100);
       ListNode* b=new ListNode(200);
       ListNode* odd=a;
       ListNode* even=b;
       ListNode* temp=head;

       int idx=1;
       while(temp){
          if(idx%2!=0){
             odd->next=temp;
             odd=odd->next;
          } else{
            even->next=temp;
            even=even->next;
          }
          temp=temp->next;
          idx++;
       }

       odd->next=b->next;
       even->next=NULL;
       return a->next;

    }
    
};

int main(){
    ListNode* a=new ListNode(10);
    ListNode* b=new ListNode(20);
    ListNode* c=new ListNode(30);
    ListNode* d=new ListNode(40);
    ListNode* e=new ListNode(50);
    ListNode* f=new ListNode(60);
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;


  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.oddEvenList(a);
    display(ans);
    
 

    
    
}
