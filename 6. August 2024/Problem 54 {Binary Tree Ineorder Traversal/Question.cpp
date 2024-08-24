/*
# 94. Binary Tree Inorder Traversal
*/
/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

*/
#include<iostream>
#include<climits>
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
class Solution{
    public:
     void helper(TreeNode* root,vector<int>& ans){
              if(root==NULL) return;
              helper(root->left,ans);
              ans.push_back(root->val);
              helper(root->right,ans);
     }
     vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       helper(root,ans);
       return ans;
    }
};

int main(){
      TreeNode* a=new TreeNode(1);
       TreeNode* b=new TreeNode(2);
       TreeNode* c=new TreeNode(3);
       TreeNode* d=new TreeNode(4);
       TreeNode* e=new TreeNode(5);
       TreeNode* f=new TreeNode(6);
       TreeNode* g=new TreeNode(7);

      a->left=b;
      a->right=c;
      b->left=d;
      b->right=e;
      c->left=f;
      c->right=g;


     Solution sol;
    vector<int> ans= sol.inorderTraversal(a);
    
    for(auto el:ans){
        cout<<el<<" ";
    }
   

   
}