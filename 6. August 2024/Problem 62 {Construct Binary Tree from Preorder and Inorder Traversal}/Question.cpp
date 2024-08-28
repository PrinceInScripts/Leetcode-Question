/*
# 105. Construct Binary Tree from Preorder and Inorder Traversal
*/
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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


class Solution{
    public:
    
    TreeNode* build(vector<int>& preorder,int preLo,int preHi, vector<int>& inorder,int inLo,int inHi){
          if(preLo>preHi) return NULL;
          TreeNode* root=new TreeNode(preorder[preLo]);
          if(preLo==preHi) return root;
          int idx=inLo;
          while(idx<inHi){
             if(inorder[idx]==preorder[preLo]) break;
             idx++;
          }

          int leftCount=idx-inLo;
          int rightCount=inHi-idx;
          root->left=build(preorder,preLo+1,preLo+leftCount,inorder,inLo,idx-1);
          root->right=build(preorder,preLo+leftCount+1,preHi,inorder,idx+1,inHi);

          return root;
    }
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n=preorder.size();
       return build(preorder,0,n-1,inorder,0,n-1);
    }
};

int main(){
     vector<int> prOrder={};
     vector<int> inOrder={};


     Solution sol;
   TreeNode* ans= sol.buildTree(prOrder,inOrder);
    
   
   

   
}