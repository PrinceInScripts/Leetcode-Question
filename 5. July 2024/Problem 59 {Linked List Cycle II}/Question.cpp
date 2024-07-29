


/*
# 142. Linked List Cycle ||
*/
/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
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
   ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_set<ListNode*> map;
        
        while(temp!=NULL){
            if(map.count(temp)){
                return temp;
            } else{
                map.insert(temp);
            }
           temp=temp->next;

        }

        
        return NULL;
       
    }
     
    
};

int main(){
    ListNode* a=new ListNode(4);
    ListNode* b=new ListNode(1);
    ListNode* c=new ListNode(8);
    ListNode* d=new ListNode(4);

 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=c;

    // display(a);

    Solution s1;
    ListNode* ans=s1.detectCycle(a);
    // display(a);
    cout<<ans->val;
 

    
    
}
