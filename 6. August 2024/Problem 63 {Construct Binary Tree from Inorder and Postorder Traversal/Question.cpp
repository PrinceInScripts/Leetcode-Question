/*
# 106. Construct Binary Tree from Inorder and Postorder Traversal
*/
/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    
    TreeNode* build(vector<int>& inorder,int inLo,int inHi, vector<int>& postorder,int postLo,int postHi){
        //   if(preLo>preHi) return NULL;
          TreeNode* root=new TreeNode(postorder[postHi]);
        //   if(preLo==preHi) return root;
          int idx=inLo;
          while(idx<inHi){
             if(inorder[idx]==postorder[postHi]) break;
             idx++;
          }

          int leftCount=idx-inLo;
          int rightCount=inHi-idx;
          root->left=build(inorder,inLo,idx-1,postorder,postLo,postLo+leftCount-1);
          root->right=build(inorder,idx+1,inHi,postorder,postLo+1,postHi-1);

          return root;
    }
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n=postorder.size();
       return build(inorder,0,n-1,postorder,0,n-1);
    }
};

int main(){
     vector<int> prOrder={};
     vector<int> inOrder={};


     Solution sol;
   TreeNode* ans= sol.buildTree(prOrder,inOrder);
    
   
   

   
}