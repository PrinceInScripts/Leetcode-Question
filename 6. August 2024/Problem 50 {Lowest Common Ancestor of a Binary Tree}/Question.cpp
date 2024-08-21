/*
# 226. Invert Binary Tree
*/
/*
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

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
class Solution1{
    public:
    bool helper(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return (helper(root->left,target) || helper(root->right,target));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(helper(root->left,p) && helper(root->right,q)) return root;
        else if(helper(root->right,p) && helper(root->left,q)) return root;
        else if(helper(root->left,p) && helper(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};
class Solution{
    public:
    bool helper(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return (helper(root->left,target) || helper(root->right,target));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(helper(root->left,p) && helper(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(helper(root->right,p) && helper(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};

int main(){
     TreeNode* a=new TreeNode(1);
     TreeNode* b=new TreeNode(2);
     TreeNode* c=new TreeNode(3);
     
     a->left=b;
     a->right=c;


     Solution sol;
    TreeNode* ans= sol.lowestCommonAncestor(a,b,c);
    cout<<ans->val;

   

   
}