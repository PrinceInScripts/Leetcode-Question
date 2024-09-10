


/*
# 2807. Insert Greatest Common Divisors in Linked List
*/
/*
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:


Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
Example 2:


Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
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
   
    int GCD(int a,int b){
        int mn=min(a,b);
        while(mn>0){
            if(a%mn==0 && b%mn==0) break;
            mn--;
        }
        return mn;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
         if(head==NULL||head->next==NULL) return head;
         ListNode* prev=head;
         ListNode* nt=head->next;
         while(prev->next!=NULL){
            ListNode* t=new ListNode(GCD(prev->val,nt->val));
            prev->next=t;
            t->next=nt;
            prev=prev->next->next;
            nt=nt->next;
         }
         return head;
    }
    
};

int main(){
    ListNode* a=new ListNode(18);
    ListNode* b=new ListNode(6);
    ListNode* c=new ListNode(10);
    ListNode* d=new ListNode(3);
 

   a->next=b;
   b->next=c;
   c->next=d;

    display(a);
   

    Solution s1;
    ListNode* ans=s1.insertGreatestCommonDivisors(a);
   
    display(ans);
    cout<<ans;
 

    
    
}
