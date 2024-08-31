/*
# 669. Trim a Binary Search Tree
*/
/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

 

Example 1:


Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]
Example 2:


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
The value of each node in the tree is unique.
root is guaranteed to be a valid binary search tree.
0 <= low <= high <= 104
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
    void helper(TreeNode* root,int low,int high){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val<low){
               root->left=root->left->right;
            }
            else if(root->left->val>high){
               root->left=root->left->left;
            }
             else break;
        }
        while(root->right!=NULL){
            if(root->right->val>high){
               root->right=root->right->left;
            }
            else if(root->right->val<low){
               root->right=root->right->right;
            }
             else break;
        }
        helper(root->left,low,high);
        helper(root->right,low,high);
            
       
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* temp=new TreeNode(INT_MAX);
        temp->left=root;
        
        helper(temp,low,high);
        return temp->left;
    }
};

void display(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

int main(){
       TreeNode* a=new TreeNode(3);
       TreeNode* b=new TreeNode(0);
       TreeNode* c=new TreeNode(4);
       TreeNode* d=new TreeNode(2);
       TreeNode* e=new TreeNode(1);

      a->left=b;
      a->right=c;
      b->right=d;
      d->right=e;
    
     display(a);
     cout<<endl;

     Solution sol;
   TreeNode* ans= sol.trimBST(a,1,3);
    
   display(ans);
   

   
}