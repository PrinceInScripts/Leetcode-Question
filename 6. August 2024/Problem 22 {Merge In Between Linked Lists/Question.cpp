


/*
# 1669. Merge In Between Linked Lists
*/
/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* x=NULL;
        ListNode* y=NULL;
        ListNode* z=NULL;
        ListNode* temp=list1;

        int idx=1;
        while(temp){
           if(idx==a) x=temp;
           if(idx==b+1) y=temp;
           if(idx==b+2) z=temp;
           temp=temp->next;
           idx++;
        }
        temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=z;
        x->next=list2;
        y->next=NULL;
        
        return list1;
    }
    
};

int main(){
    ListNode* a=new ListNode(0);
    ListNode* b=new ListNode(1);
    ListNode* c=new ListNode(2);
    ListNode* d=new ListNode(3);
    ListNode* e=new ListNode(4);
    ListNode* f=new ListNode(5);
    ListNode* g=new ListNode(6);

    ListNode* h=new ListNode(10000000);
    ListNode* i=new ListNode(10000000);
    ListNode* j=new ListNode(10000000);
    ListNode* k=new ListNode(10000000);

    h->next=i;
    i->next=j;
    j->next=k;
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;
   f->next=g;


  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.mergeInBetween(a,2,5,h);
    display(ans);
    
 

    
    
}
