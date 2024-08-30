/*
# 98. Validate Binary Search Tree
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    long long maxNode(TreeNode* root){
         if(root==NULL) return LLONG_MIN;
         return max((long long)root->val,max(maxNode(root->left),maxNode(root->right)));
    }
    long long minNode(TreeNode* root){
         if(root==NULL) return LLONG_MAX;
         return min((long long)root->val,min(minNode(root->left),minNode(root->right)));
    }
    bool isValidBST(TreeNode* root) {
         if(root==NULL) return true;
          else  if(root->val>maxNode(root->left) && root->val<minNode(root->right)){
            return isValidBST(root->left) && isValidBST(root->right);
          } else {
            return false;
          }
    }
};
class Solution2{
    public:
    void inOrder(TreeNode* root,vector<int>& ans){
       if(root==NULL) return;
       inOrder(root->left,ans);
       ans.push_back(root->val);
       inOrder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inOrder(root,ans);

        for(int i=1;i<ans.size();i++){
            if(ans[i]<ans[i-1]) return false;
        }
        return true;
    }
};
class Solution{
    public:
    TreeNode* prev=NULL;
    bool flag=true;
    void inOrder(TreeNode* root){
       if(root==NULL) return;
       inOrder(root->left);
       if(prev!=NULL){
        if(root->val<=prev->val){
          flag=false;
          return;
        }
       }
       inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return flag;
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
      TreeNode* p=new TreeNode(0);
      TreeNode* q=new TreeNode(6);
      

     Solution sol;
   bool ans= sol.isValidBST(a);
    
   cout<<ans<<endl;
   
   

   
}