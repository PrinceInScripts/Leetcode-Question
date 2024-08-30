/*
# 701.  Insert into a Binary Search Tree
*/
/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.
*/
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
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


class Solution1{
    public:
     void helper(TreeNode* root,int val){
         if(root->val<val){
            if(root->right==NULL) root->right=new TreeNode(val);
            else helper(root->right,val);
         } 
         else {
            if(root->left==NULL) root->left=new TreeNode(val);
            else helper(root->left,val);
         }
     }
     TreeNode* insertIntoBST(TreeNode* root, int val) {
       helper(root,val);
       return root;
        
    }
};
class Solution{
    public:
    
     TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root=new TreeNode(val);
            return root;
         }
        else if(root->val<val){
            if(root->right==NULL) root->right=new TreeNode(val);
            else insertIntoBST(root->right,val);
         } 
         else {
            if(root->left==NULL)root->left=new TreeNode(val);
            else insertIntoBST(root->left,val);
         }

         return root;
        
    }
};

int main(){
      TreeNode* a=new TreeNode(4);
       TreeNode* b=new TreeNode(2);
       TreeNode* c=new TreeNode(7);
       TreeNode* d=new TreeNode(1);
       TreeNode* e=new TreeNode(3);
      

      a->left=b;
      a->right=c;
      b->left=d;
      b->right=e;


     Solution sol;
   TreeNode* ans= sol.insertIntoBST(a,5);
    
   cout<<ans->val<<endl;
   
   

   
}