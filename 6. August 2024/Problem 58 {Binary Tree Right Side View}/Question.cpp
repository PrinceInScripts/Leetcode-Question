/*
# 199. Binary Tree Right Side View
*/
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
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
   
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+(max(level(root->left),level(root->right)));
    }

    void nthLevel(TreeNode* root,int curr,int level,vector<int>& ans){
        if(root==NULL) return;
        if(curr==level) {
            ans[curr]=root->val;
            return;
        }
        nthLevel(root->left,curr+1,level,ans);
        nthLevel(root->right,curr+1,level,ans);
    
      }

      void levelOrder(TreeNode* root,vector<int>& ans){
       int n=ans.size();
       for(int i=0;i<n;i++){
          nthLevel(root,0,i,ans);
       }

}
     vector<int> rightSideView(TreeNode* root) {
      vector<int> ans(level(root));
      levelOrder(root,ans);
       return ans;
    }
};
class Solution{
    public:
   
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+(max(level(root->left),level(root->right)));
    }

   
    void preOrder(TreeNode* root,vector<int>& ans,int level){
            if(root==NULL) return;
            ans[level]=root->val;
            preOrder(root->left,ans,level+1);
            preOrder(root->right,ans,level+1);
     }
     vector<int> rightSideView(TreeNode* root) {
      vector<int> ans(level(root));
      preOrder(root,ans,0);
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
    vector<int> ans= sol.rightSideView(a);
    
    for(auto el:ans){
            cout<<el<<" ";
        cout<<endl;
    }
   

   
}