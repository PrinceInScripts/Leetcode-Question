


/*
# 1367. Linked List in Binary Tree
*/
/*
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.
*/


#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class TreeNode{
public:
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
     }
};
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
   
    bool helper(ListNode* head, TreeNode* root){
        if(head==NULL) return false;
        if(root==NULL) return false;
        if(root->val!=head->val) return false;
        
        return helper(head->next,root->left) || helper(head->next,root->right);

    }
     bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        return isSubPath(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
    
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(4);
    ListNode* c=new ListNode(2);
    ListNode* d=new ListNode(6);
    ListNode* e=new ListNode(8);
 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;

   TreeNode* a1=new TreeNode(1);
   TreeNode* b1=new TreeNode(4);
   TreeNode* c1=new TreeNode(4);
   TreeNode* d1=new TreeNode(2);
   TreeNode* e1=new TreeNode(2);
   TreeNode* f1=new TreeNode(1);
   TreeNode* g1=new TreeNode(6);
   TreeNode* h1=new TreeNode(8);
   TreeNode* i1=new TreeNode(1);
   TreeNode* j1=new TreeNode(3);

   a1->left=b1;
   a1->right=c1;
   b1->right=d1;
   c1->left=e1;
   d1->left=f1;
   e1->left=g1;  
   e1->right=h1; 
   h1->left=i1;
   h1->left=j1; 
   


    display(a);
   

    Solution s1;
    bool ans=s1.isSubPath(a,a1);
   
    // display(ans);
    cout<<ans;
 

    
    
}
