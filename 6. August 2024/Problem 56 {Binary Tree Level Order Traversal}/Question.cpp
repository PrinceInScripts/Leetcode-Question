/*
# 102. Binary Tree Level Order Traversal
*/
/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].

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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+(max(level(root->left),level(root->right)));
    }
     void nthLevel(TreeNode* root,int curr,int lev,vector<int>& ans){
              if(root==NULL) return;
              if(curr==lev){
                    ans.push_back(root->val);
                    return;
              }
              nthLevel(root->left,curr+1,lev,ans);
              nthLevel(root->right,curr+1,lev,ans);
             
     }
     void helper(TreeNode* root,vector<vector<int>>& ans){
             int n=level(root);
            for(int i=1;i<=n;i++){
            vector<int> ansHelp;
            nthLevel(root,1,i,ansHelp);
            ans.push_back(ansHelp);
             }
     }
     vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       
        helper(root,ans);
      
       return ans;
    }
};
class Solution{
    public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+(max(levels(root->left),levels(root->right)));
    }
     void helper(TreeNode* root,vector<vector<int>>& ans,int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        helper(root->left,ans,level+1);
        helper(root->right,ans,level+1);  
     }
     vector<vector<int>> levelOrder(TreeNode* root) {
       int n=levels(root);
       vector<vector<int>> ans;
       for(int i=1;i<=n;i++){
        vector<int> v;
        ans.push_back(v);
       }
        helper(root,ans,0);
      
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
       TreeNode* g=new TreeNode(7);

      a->left=b;
      a->right=c;
      b->left=d;
      b->right=e;
      c->left=f;
      c->right=g;


     Solution sol;
    vector<vector<int>> ans= sol.levelOrder(a);
    
    for(auto el:ans){
        for(auto val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }
   

   
}