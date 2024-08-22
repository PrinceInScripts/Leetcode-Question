/*
# 110. Balanced Binary Tree
*/
/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

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
    int checkHeights(TreeNode* root){
       if(root==NULL) return 0;
       int leftHeights=checkHeights(root->left);
       if(leftHeights==-1) return -1;
       int rightHeights=checkHeights(root->right);
       if(rightHeights==-1) return -1;
       if(abs(leftHeights-rightHeights)>1) return -1;
       return 1+max(checkHeights(root->left),checkHeights(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(checkHeights(root)==-1) return false;
        else return true;
    }
};

int main(){
     TreeNode* a=new TreeNode(1);
     TreeNode* b=new TreeNode(2);
     TreeNode* c=new TreeNode(3);
     
     a->left=b;
     a->right=c;


     Solution sol;
    bool ans= sol.isBalanced(a);
    cout<<ans;

   

   
}