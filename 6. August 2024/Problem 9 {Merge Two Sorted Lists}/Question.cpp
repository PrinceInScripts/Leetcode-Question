


/*
# 21. Merge Two Sorted Lists
*/
/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

     if(list1==NULL && list2==NULL) return NULL;
     else if(list1==NULL) return list2;
     else if(list2==NULL) return list1;
    
      ListNode* temp1=list1;
      ListNode* temp2=list2;

      while(temp1->next!=NULL && temp2->next!=NULL){
         if(temp2->val>=temp1->val){
            ListNode* temp3=temp2->next;
            ListNode* temp4=temp1->next;

            temp2->next=temp1->next;
            temp1->next=temp2;
            temp1=temp4;
            temp2=temp3;
         } else {
            temp1=temp1->next;
         }
      }
       if(temp2->val>=temp1->val){
            ListNode* temp3=temp2->next;
            ListNode* temp4=temp1->next;

            temp2->next=temp1->next;
            temp1->next=temp2;
            temp1=temp4;
            temp2=temp3;
         } else {
            temp1=temp1->next;
         }

      while(temp2!=NULL){
            temp1->next=temp2;
      }
      while(temp1!=NULL){
        temp2->next=temp1;
      }

      return list1;

       
    }
  
   
    
};

int main(){
    ListNode* a1=new ListNode(1);
    ListNode* b1=new ListNode(2);
    ListNode* c1=new ListNode(4);

    ListNode* a2=new ListNode(1);
    ListNode* b2=new ListNode(3);
    ListNode* c2=new ListNode(4);

   

 

   a1->next=b1;
   b1->next=c1;

   a2->next=b2;
   b2->next=c2;
   


    display(a1);
    display(a2);


    Solution s1;
    ListNode* ans=s1.mergeTwoLists(a1,a2);
    display(ans);
 

    
    
}
