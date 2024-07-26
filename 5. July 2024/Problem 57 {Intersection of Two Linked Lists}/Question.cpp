

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
              ListNode* temp1=headA;
              ListNode* temp2=headB;

              int len1=0,len2=0;
              while(temp1!=NULL){
                len1++;
                temp1=temp1->next;
              }
              while(temp2!=NULL){
                len2++;
                temp2=temp2->next;
              }
             
            temp1=headA;
            temp2=headB;
              if(len1>len2){
                for(int i=1;i<=len1-len2;i++){
                    temp1=temp1->next;
                }
              } else{
                for(int i=1;i<=len2-len1;i++){
                    temp2=temp2->next;
                }
              }
             while(temp1!=NULL && temp2!=NULL){
                if(temp1==temp2){
                    return temp1;
                } else {
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
             }
             return NULL;
    }
    
};

int main(){
    ListNode* a1=new ListNode(4);
    ListNode* b1=new ListNode(1);
    ListNode* c=new ListNode(8);
    ListNode* d=new ListNode(4);
    ListNode* e=new ListNode(5);

    ListNode* a2=new ListNode(5);
    ListNode* b2=new ListNode(6);
    ListNode* c2=new ListNode(1);

    a1->next=b1;
    b1->next=c;
    c->next=d;
    d->next=e;
    a2->next=b2;
    b2->next=c2;
    c2->next=c;

    display(a1);

    Solution s1;
    ListNode* ans=s1.getIntersectionNode(a1,a2);
    display(a2);
    cout<<ans->val;
 

    
    
}
