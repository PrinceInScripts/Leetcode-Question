/*
# 112. Path Sum
*/
/*


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
    bool flag(TreeNode* root,int targetSum,int sum){
          if(root==NULL) return false;
          sum+=root->val;
          if(root->left==NULL && root->right==NULL){
              return sum==targetSum;
          }
          return flag(root->left,targetSum,sum) || flag(root->right,targetSum,sum);
                    
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
            if(flag(root,targetSum,0)) return true;
            else return false;
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
    bool ans= sol.hasPathSum(a,2);
    
    cout<<ans;
   

   
}