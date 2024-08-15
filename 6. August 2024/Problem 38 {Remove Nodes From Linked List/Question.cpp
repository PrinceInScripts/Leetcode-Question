


/*
# 2487. Remove Nodes From Linked List
*/
/*
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105

*/


#include<iostream>
#include<stack>
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
 
  ListNode* removeNodes(ListNode* head) {
      stack<ListNode*> st;
      ListNode* temp=head;
      st.push(temp);
      temp=temp->next;
      while(temp){
         while(st.size()>0 && temp->val>st.top()->val){
            st.pop();
         }
         st.push(temp);
         temp=temp->next;
      }

      temp=NULL;
      while(st.size()>0){
         st.top()->next=temp;
         temp=st.top();
         st.pop();
      }

      return temp;

   }
   
    
};

int main(){
    ListNode* a=new ListNode(5);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(13);
    ListNode* d=new ListNode(3);
    ListNode* e=new ListNode(8);
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;

  
   


    display(a);
   

    Solution s1;
    ListNode* ans=s1.removeNodes(a);
    display(ans);
    
 

    
    
}
