/*
# 1008. Construct Binary Search Tree from Preorder Traversal
/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
 
*/
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
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
    TreeNode* helper(vector<int>& preorder,int preLo,int preHi,vector<int>& inorder,int inLo,int inHi){
          if(preLo>preHi) return NULL;
          TreeNode* root=new TreeNode(preorder[preLo]);
          if(preLo==preHi) return root;
          int idx=inLo;
          while(idx<inHi){
            if(inorder[idx]==root->val) break;
            idx++;
          }
          int leftCount=idx-inLo;
          int rightCount=inHi-idx+1;
          root->left=helper(preorder,preLo+1,preLo+leftCount,inorder,inLo,idx-1);
          root->right=helper(preorder,preLo+leftCount+1,preHi,inorder,idx+1,inHi);
          return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=preorder.size();
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
};
class Solution{
    public:
      void insert(TreeNode* root,int val){
         if(root->val<val){
            if(root->right==NULL) root->right=new TreeNode(val);
            else insert(root->right,val);
         } 
         else {
            if(root->left==NULL) root->left=new TreeNode(val);
            else insert(root->left,val);
         }
     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode* root=new TreeNode(preorder[0]);
       for(int i=1;i<preorder.size();i++){
          insert(root,preorder[i]);
       }
       return root;
    }
};



int main(){
    
   
   

   
}