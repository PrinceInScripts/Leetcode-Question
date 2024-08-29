/*
# 700. Search in a Binary Search Tree
*/
/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
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
    
    TreeNode* searchBST(TreeNode* root, int val) {
       if(root->val==val) return root;
       else if(root->val<val) return searchBST(root->right,val);
       else if(root->val>val) return searchBST(root->left,val);
       return NULL;

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


     Solution sol;
   TreeNode* ans= sol.searchBST(a,2);
    
   cout<<ans->val<<endl;
   
   

   
}