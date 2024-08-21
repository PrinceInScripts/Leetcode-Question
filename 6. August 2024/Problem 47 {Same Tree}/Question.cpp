
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
class Solution{
    public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL && q!=NULL) return false;
        if(p!=NULL && q==NULL) return false;
        if(p->val!=q->val) return false;
        bool isLST=isSameTree(p->left,q->left);
        if(!isLST) return false;
        bool isRST=isSameTree(p->right,q->right);
        if(!isRST) return false;
        return true;

    }
};

int main(){
     TreeNode* a=new TreeNode(1);
     TreeNode* b=new TreeNode(2);
     TreeNode* c=new TreeNode(3);
     TreeNode* a1=new TreeNode(1);
     TreeNode* b1=new TreeNode(2);
     TreeNode* c1=new TreeNode(3);
    
     a->left=b;
     a->right=c;

     a1->left=b1;
     a1->right=c1;

     Solution sol;
     cout<<sol.isSameTree(a,a1)<<endl;

   
}