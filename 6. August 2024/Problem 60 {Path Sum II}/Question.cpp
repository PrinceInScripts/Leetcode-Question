/*
# 113. Path Sum ||
*/
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
    void helper(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int> temp,int sum){
          if(root==NULL) return;
          sum+=root->val;
          temp.push_back(root->val);

          if(root->left==NULL && root->right==NULL){
              if(sum==targetSum){
                 ans.push_back(temp);
              }
          }
           helper(root->left,targetSum,ans,temp,sum);
           helper(root->right,targetSum,ans,temp,sum);
                    
    }
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
           vector<vector<int>> ans;
           vector<int> temp;
           helper(root,targetSum,ans,temp,0);
            return ans;
    }
};
class Solution{
    public:
    void helper(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int> temp){
          if(root==NULL) return;
          temp.push_back(root->val);

          if(root->left==NULL && root->right==NULL){
              if(targetSum==root->val){
                 ans.push_back(temp);
              }
              return;
          }
           helper(root->left,targetSum-root->val,ans,temp);
           helper(root->right,targetSum-root->val,ans,temp);
                    
    }
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
           vector<vector<int>> ans;
           vector<int> temp;
           helper(root,targetSum,ans,temp);
            return ans;
    }
};

int main(){
      TreeNode* a=new TreeNode(1);
       TreeNode* b=new TreeNode(2);
       TreeNode* c=new TreeNode(3);
       TreeNode* d=new TreeNode(4);
       TreeNode* e=new TreeNode(5);
       TreeNode* f=new TreeNode(6);
       TreeNode* g=new TreeNode(4);

      a->left=b;
      a->right=c;
      b->left=d;
      b->right=e;
      c->left=f;
      c->right=g;


     Solution sol;
    vector<vector<int>> ans= sol.pathSum(a,8);
    
    for(auto el:ans){
        for(auto val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }
   
   

   
}