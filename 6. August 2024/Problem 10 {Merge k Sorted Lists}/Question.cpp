


/*
# 23. Merge k Sorted Lists
*/
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
   ListNode* merge(ListNode* a,ListNode* b){
      ListNode* c=new ListNode(10);
      ListNode* temp=c;

      while(a!=NULL && b!=NULL){
         if(a->val<=b->val){
             temp->next=a;
             temp=temp->next;
             a=a->next;
         } else {
            temp->next=b;
            temp=temp->next;
            b=b->next;
         }
      }

      if(a==NULL) temp->next=b;
      else temp->next=a;

      return c->next;
   }
   ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[0];
            lists.erase(lists.begin());
            ListNode* b=lists[0];
            lists.erase(lists.begin());
            lists.push_back(merge(a,b));
        }

        return lists[0];
    }
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[lists.size()-1];
            lists.pop_back();
            ListNode* b=lists[lists.size()-1];
            lists.pop_back();
            lists.push_back(merge(a,b));
        }

        return lists[0];
    }
    
};

int main(){
    ListNode* a1=new ListNode(1);
    ListNode* b1=new ListNode(2);
    ListNode* c1=new ListNode(4);

    ListNode* a2=new ListNode(1);
    ListNode* b2=new ListNode(3);
    ListNode* c2=new ListNode(4);

    ListNode* a3=new ListNode(2);
    ListNode* b3=new ListNode(6);

   a1->next=b1;
   b1->next=c1;

   a2->next=b2;
   b2->next=c2;

   a3->next=b3;
   


    display(a1);
    display(a2);
    display(a3);

    vector<ListNode*> lists={a1,a2,a3};


    Solution s1;
    ListNode* ans=s1.mergeKLists(lists);
    display(ans);
 

    
    
}
