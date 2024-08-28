/*
# 437. Path Sum |||
*/
/*
437. Path Sum III
Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
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

class Solution1{
    public:
    
     int check(TreeNode* root,long long targetSum){
        if(root==NULL) return false;
        targetSum-=root->val;
        int count=0;
        if(targetSum==0) count++;
       count+=check(root->left,targetSum);
       count+=check(root->right,targetSum);

       return count;
    }
    int helper(TreeNode* root,long long targetSum){
        if(root==NULL) return 0;

       int count=check(root,targetSum);

       count+=helper(root->left,targetSum);
       count+=helper(root->right,targetSum);

       return count;

                    
    }
    int pathSum(TreeNode* root, long long targetSum) {
        
         return  helper(root,static_cast<long long>(targetSum));
           
    }
};
class Solution{
    public:
    
    void helper(TreeNode* root,long long targetSum,int& count){
       if(root==NULL) return;
        targetSum-=root->val;
        if(targetSum==0) count++;
       helper(root->left,targetSum,count);
       helper(root->right,targetSum,count);       
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root==NULL) return 0;
         int count=0;
         helper(root,targetSum,count);
         count+=pathSum(root->left,targetSum)+pathSum(root->right,(long long)targetSum);
         return  count;
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
   int ans= sol.pathSum(a,8);
    
   cout<<ans;
   
   

   
}