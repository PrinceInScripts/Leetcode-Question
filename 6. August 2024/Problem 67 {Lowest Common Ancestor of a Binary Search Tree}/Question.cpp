/*
# 235.  Lowest Common Ancestor of a Binary Search Tree
*/
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root->val==p->val || root->val==q->val) return root;
         if(root->val>p->val && root->val<q->val) return root;
         else if(root->val<p->val && root->val>q->val) return root;
         else if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
         else return lowestCommonAncestor(root->left,p,q);
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
   TreeNode* ans= sol.lowestCommonAncestor(a,p,q);
    
   cout<<ans->val<<endl;
   
   

   
}