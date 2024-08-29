/*
# 897. Construct Binary Tree from Preorder and Postorder Traversal
*/
/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
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
    
    TreeNode* build(vector<int>& preorder,int preLo,int preHi, vector<int>& postorder,int postLo,int postHi){
          if(preLo>preHi) return NULL;
          TreeNode* root=new TreeNode(preorder[preLo]);
          if(preLo==preHi) return root;
          int idx=postLo;
          while(idx<=postHi){
             if(postorder[idx]==preorder[preLo+1]) break;
             idx++;
          }

          int leftCount=idx-postLo+1;
          int rightCount=postHi-idx-1;
          root->left=build(preorder,preLo+1,preLo+leftCount,postorder,postLo,idx);
          root->right=build(preorder,preLo+leftCount+1,preHi,postorder,idx+1,postHi-1);

          return root;
    }
   TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       int n=postorder.size();
       return build(preorder,0,n-1,postorder,0,n-1);
    }
};

int main(){
     vector<int> preOrder={};
     vector<int> postOrder={};


     Solution sol;
   TreeNode* ans= sol.constructFromPrePost(preOrder,postOrder);
    
   
   

   
}