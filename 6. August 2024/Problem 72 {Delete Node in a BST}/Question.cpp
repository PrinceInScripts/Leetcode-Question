/*
# 450. Delete Node in a BST
*/
/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?
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


class Solution{
    public:
    TreeNode* predecessor(TreeNode* root){
        root=root->left;
        while(root->right){
            root=root->right;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL) return NULL;
       else if(root->val==key){
             //0 child node
             if(root->left==NULL && root->right==NULL){
                return NULL;
             }
             //1 child Node
             else if(root->left==NULL || root->right==NULL){
                   if(root->left!=NULL) return root->left;
                   else return root->right;
             }
             //2 child Node
             else{
                 TreeNode* t=predecessor(root);
                 root->val=t->val;
                 root->left=deleteNode(root->left,t->val);

             }
            
       } else if(root->val>key) root->left=deleteNode(root->left,key);
       else root->right=deleteNode(root->right,key);
       return root;
    }
};

void display(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

int main(){
       TreeNode* a=new TreeNode(5);
       TreeNode* b=new TreeNode(3);
       TreeNode* c=new TreeNode(6);
       TreeNode* d=new TreeNode(2);
       TreeNode* e=new TreeNode(4);
       TreeNode* g=new TreeNode(7);

      a->left=b;
      a->right=c;
      b->left=d;
      b->right=e;
      c->right=g;
    
     display(a);
     cout<<endl;

     Solution sol;
   TreeNode* ans= sol.deleteNode(a,5);
    
   display(ans);
   
   

   
}