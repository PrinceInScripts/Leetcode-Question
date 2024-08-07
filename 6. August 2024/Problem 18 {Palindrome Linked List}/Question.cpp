


/*
# 234. Palindrome Linked List
*/
/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
       ListNode* Next=head->next;
      

       while(Curr!=NULL){
          Next=Curr->next;
          Curr->next=Prev;
          Prev=Curr;
          Curr=Next;
       }
       return Prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* c=new ListNode(10);
        ListNode* tempC=c;
        while(temp!=NULL){
            ListNode* node=new ListNode(temp->val);
            tempC->next=node;
            temp=temp->next;
            tempC=tempC->next;
        }
       ListNode* rev= reverse(c->next);
       
       temp=head;
       while(temp!=NULL && rev!=NULL){
          if(temp->val!=rev->val) return false;
          temp=temp->next;
          rev=rev->next;
       }
        
      

       return true;
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(1);
    ListNode* c=new ListNode(2);
    ListNode* d=new ListNode(1);
 

   a->next=b;
   b->next=c;
   c->next=d;

  
   


    display(a);
   

    Solution s1;
    cout<<s1.isPalindrome(a);
    // ListNode* ans=s1.reverse(a);
    // display(ans);
 

    
    
}
