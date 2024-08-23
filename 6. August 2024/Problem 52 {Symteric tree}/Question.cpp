/*
# 101. Symmetric  Tree
*/
/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?

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
    bool helper(TreeNode* root1,TreeNode* root2){
          if(root1==NULL && root2==NULL) return true;
          else if(root1==NULL && root2!=NULL) return false;
          else if(root2==NULL && root1!=NULL) return false;
          else if(root1->val!=root2->val) return false;
          helper(root1->left,root2->right);
          helper(root1->right,root2->left);
          return true;
          
    }
    bool isSymmetric(TreeNode* root) {
        if(helper(root->left,root->right)) return true;
        else return false;
    }
};

int main(){
     TreeNode* a=new TreeNode(1);
     TreeNode* b=new TreeNode(2);
     TreeNode* c=new TreeNode(2);
     
     a->left=b;
     a->right=c;


     Solution sol;
    bool ans= sol.isSymmetric(a);
    cout<<ans;

   

   
}