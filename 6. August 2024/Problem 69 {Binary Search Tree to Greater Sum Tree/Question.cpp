/*
# 1038. Binary Search Tree to Greater Sum Tree
/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
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
    void helper(TreeNode* root,int& sum){
        if(root==NULL) return;
        helper(root->right,sum);
        root->val+=sum;
        sum=root->val;
        helper(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        helper(root,sum);
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
      TreeNode* p=new TreeNode(0);
      TreeNode* q=new TreeNode(6);
      

     Solution sol;
   TreeNode* ans= sol.bstToGst(a);
    
   cout<<ans->val<<endl;
   
   

   
}