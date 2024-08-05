


/*
# 86. Partition List
*/
/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo=new ListNode(10);
        ListNode* hi=new ListNode(10);

        ListNode* tlo=lo;
        ListNode* thi=hi;

        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                tlo->next=temp;
                temp=temp->next;
                tlo=tlo->next;
            } else{
                thi->next=temp;
                temp=temp->next;
                thi=thi->next;
            }
        }
       
        tlo->next=hi->next;
        thi->next=NULL;

        return lo->next;

        
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(4);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(2);
    ListNode* e=new ListNode(5);
    ListNode* f=new ListNode(2);

   

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;

  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.partition(a,3);
    display(ans);
 

    
    
}
