


/*
# 3217. Delete Nodes From Linked List Present in Array
*/
/*
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:



Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:



Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:



No node has value 5.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105
The input is generated such that there is at least one node in the linked list that has a value not present in nums.
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
   
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(4);
    ListNode* e=new ListNode(5);
    
    vector<int> nums={1,2,3};
 

   a->next=b;
   b->next=c;
   c->next=d;
//    d->next=e;
//    e->next=f;

  
   


    display(a);
   

    Solution s1;
    cout<<s1.modifiedList(nums,a);
    // ListNode* ans=s1.reverse(a);
    // display(ans);
 

    
    
}
