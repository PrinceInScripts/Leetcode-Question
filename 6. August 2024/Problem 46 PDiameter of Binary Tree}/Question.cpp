
#include<iostream>
#include<climits>
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
    int mxDia=0;
    int helper(TreeNode* root){
       if(root==NULL) return 0;
        int dia= levels(root->left)+levels(root->right);
        mxDia=max(mxDia,dia);
        helper(root->left);
        helper(root->right);
        return mxDia;
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mxDia=0;
        return helper(root);
    }
};
class Solution{
    public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void helper(TreeNode* root,int &mxDia){
       if(root==NULL) return;
        int dia= levels(root->left)+levels(root->right);
        mxDia=max(mxDia,dia);
        helper(root->left,mxDia);
        helper(root->right,mxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mxDia=0;
        helper(root,mxDia);
        return mxDia;
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
     cout<<sol.diameterOfBinaryTree(a)<<endl;

   
}