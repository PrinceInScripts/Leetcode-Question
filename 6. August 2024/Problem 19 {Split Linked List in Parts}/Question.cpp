


/*
# 725. Palindrome Linked List
*/
/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

Constraints:

The number of nodes in the list is in the range [0, 1000].
0 <= Node.val <= 1000
1 <= k <= 50
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
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      vector<ListNode*> ans;
      int n=0;
      ListNode* temp=head;
      while(temp!=NULL){
         n++;
         temp=temp->next;
      }

      int part=n/k;
      int extra=n%k;
       temp=head;
      while(temp){
         ListNode* c=new ListNode(10);
         ListNode* tempC=c;
         int size=part;

         if(extra>0){
            size=size+1;
            extra--;
         }
         for(int i=1;i<=size;i++){
            tempC->next=temp;
            tempC=tempC->next;
            temp=temp->next;
         }
         tempC->next=NULL;
         c=c->next;
         ans.push_back(c);
      }
      if(ans.size()<k){
        int diff=k-ans.size();
        for(int i=1;i<=diff;i++){
            ans.push_back(NULL);
        }
      }
      return ans;


    }
    vector<ListNode*> splitListToParts1(ListNode* head, int k) {
      vector<ListNode*> ans;
      int n=0;
      ListNode* temp=head;
      while(temp!=NULL){
         n++;
         temp=temp->next;
      }
      int part=n/k;
      int extra=n%k;
      int rem=0;
      if(part<k) {
        rem=k-part;
        cout<<"hi"<<endl;
      }

      ListNode* t=head;
      int count=0;
        while(count<k){
            // ListNode* a=new ListNode(10);
            int lim=part;
            if(extra>0){
                lim++;
                extra--;
            }
            temp=t;
            for(int i=1;i<lim;i++){
               temp=temp->next;
            }
            ans.push_back(t);
            t=temp->next;
            temp->next=NULL;
            count++;
            
        }
      
      return ans;


    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(4);
    ListNode* e=new ListNode(5);
    ListNode* f=new ListNode(6);
    ListNode* g=new ListNode(7);
    ListNode* h=new ListNode(8);
    ListNode* i=new ListNode(9);
    ListNode* j=new ListNode(10);
    ListNode* k=new ListNode(11);
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;
   f->next=g;
   g->next=h;
   h->next=i;
   i->next=j;
   j->next=k;

  
   


    display(a);
   

    Solution s1;
    vector<ListNode*> ans=s1.splitListToParts(a,3);
    
    for(auto el:ans){
        display(el);
    }
 

    
    
}
