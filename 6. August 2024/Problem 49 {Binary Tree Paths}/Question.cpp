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
class Solution{
    public:
    void helper(TreeNode* root,string str,vector<string>& ans){
        string s=to_string(root->val);

       if(root->left==NULL && root->right==NULL){
           str+=s;
           ans.push_back(str);
           return;
       }
          
       helper(root->left,str+s+"->",ans);
       helper(root->right,str+s+"->",ans);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
    }
};

int main(){
     TreeNode* a=new TreeNode(1);
     TreeNode* b=new TreeNode(2);
     TreeNode* c=new TreeNode(3);
     
     a->left=b;
     a->right=c;


     Solution sol;
    vector<string> ans= sol.binaryTreePaths(a);
    for(auto el:ans){
        cout<<el<<" ";
    }

   
}