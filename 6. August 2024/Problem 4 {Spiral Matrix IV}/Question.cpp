


/*
# 2326. Spiral Matrix IV
*/
/*
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/


#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
void display(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       int minR=0,minC=0,maxR=m-1,maxC=n-1;

       ListNode* temp=head;
       vector<vector<int>> matrix(m,vector<int>(n,-1));
       
       while(minR<=maxR && minC<=maxC){
          for(int i=minC;i<=maxC;i++){
              if(temp==NULL) return matrix;
              matrix[minR][i]=temp->val;
              temp=temp->next;
          }
          minR++;
          if(minR>maxR || minC>maxC) break;
          for(int i=minR;i<=maxR;i++){
            if(temp==NULL) return matrix;
            matrix[i][maxC]=temp->val;
            temp=temp->next;
          }
          maxC--;
          if(minR>maxR || minC>maxC) break;
          for(int i=maxC;i>=minC;i--){
            if(temp==NULL) return matrix;
            matrix[maxR][i]=temp->val;
            temp=temp->next;
          }
          maxR--;
          if(minR>maxR || minC>maxC) break;
          for(int i=maxR;i>=minR;i--){
            if(temp==NULL) return matrix;
            matrix[i][minC]=temp->val;
            temp=temp->next;
          }
          minC++;
       }

       return matrix;
       
    }
  
   
    
};

int main(){
    ListNode* a=new ListNode(3);
    ListNode* b=new ListNode(0);
    ListNode* c=new ListNode(2);
    ListNode* d=new ListNode(6);
    ListNode* e=new ListNode(8);
    ListNode* f=new ListNode(1);
    ListNode* g=new ListNode(7);
    ListNode* h=new ListNode(9);
    ListNode* i=new ListNode(4);
    ListNode* j=new ListNode(2);
    ListNode* k=new ListNode(5);
    ListNode* l=new ListNode(5);
    ListNode* m=new ListNode(0);

 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;
   f->next=g;
   g->next=h;
   h->next=i;
   i->next=j;
   j->next=k;
   k->next=l;
   l->next=m;


    display(a);

    Solution s1;
    vector<vector<int>> ans=s1.spiralMatrix(3,5,a);
    for(auto arr:ans){
        for(auto el:arr){
            cout<<el<<" ";
        }
        cout<<endl;
    }
 

    
    
}
