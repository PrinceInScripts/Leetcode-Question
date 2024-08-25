/*
# 103. Binary Tree Zigzag Level Order Traversal
*/
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
class Solution{
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
     void nthLevelRev(TreeNode* root,int curr,int lev,vector<int>& ans){
              if(root==NULL) return;
              if(curr==lev){
                    ans.push_back(root->val);
                    return;
              }
              nthLevelRev(root->right,curr+1,lev,ans);
              nthLevelRev(root->left,curr+1,lev,ans);
             
     }
     void helper(TreeNode* root,vector<vector<int>>& ans){
             int n=level(root);
            for(int i=1;i<=n;i++){
            vector<int> ansHelp;
            if(i%2!=0) nthLevel(root,1,i,ansHelp);
            else nthLevelRev(root,1,i,ansHelp);
            
            ans.push_back(ansHelp);
             }
     }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       
        helper(root,ans);
      
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
    vector<vector<int>> ans= sol.zigzagLevelOrder(a);
    
    for(auto el:ans){
        for(auto val:el){
            cout<<val<<" ";
        }
        cout<<endl;
    }
   

   
}