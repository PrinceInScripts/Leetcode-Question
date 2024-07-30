


/*
# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
*/
/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105

*/


#include<iostream>
#include<unordered_set>
#include<vector>
#include<limits.h>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> local;
       ListNode* temp=head;
       int count=2;
       while(temp->next->next!=NULL){

          if((temp->next->val>temp->val) && (temp->next->val>temp->next->next->val)){
            local.push_back(count);
          }
          if((temp->next->val<temp->val) && (temp->next->val<temp->next->next->val)){
            local.push_back(count);
          }
          temp=temp->next;
          count++;
       }

       int minLocal=INT_MAX;
       int maxLocal;
       if(local.size()<2) return {-1,-1};
       else {
         for(int i=1;i<local.size();i++){
            minLocal=min(minLocal,local[i]-local[i-1]);
         }
         maxLocal=local.back()-local.front();
       }

       return {minLocal,maxLocal};
       
   
    }
    vector<int> nodesBetweenCriticalPoints1(ListNode* head) {
       vector<int> local;
       ListNode* temp=head;
       int count=2;
       while(temp->next->next!=NULL){

          if((temp->next->val>temp->val) && (temp->next->val>temp->next->next->val)){
            local.push_back(count);
          }
          if((temp->next->val<temp->val) && (temp->next->val<temp->next->next->val)){
            local.push_back(count);
          }
          temp=temp->next;
          count++;
       }

       int min=-1;
       int max=-1;
       if(local.size()==0) return {min,max};
       else {
          for(int i=1;i<local.size();i++){
              
              if(min==-1 && max==-1) {
                int diff=local[i]-local[i-1];
                min=diff;
                max=diff;
              }
              else if(i>1){
                int j=i-1;
              while(j>=0){
                int diff1=local[i]-local[j];
                if(diff1>max){
                    max=diff1;
                } else if(diff1<min){
                    min=diff1;
                }
                j--;
              }
              }

          }
       }
       return {min,max};
   
    }
     
   
    
};

int main(){
    ListNode* a=new ListNode(5);
    ListNode* b=new ListNode(3);
    ListNode* c=new ListNode(1);
    ListNode* d=new ListNode(2);
    ListNode* e=new ListNode(5);
    ListNode* f=new ListNode(1);
    ListNode* g=new ListNode(2);

 

   a->next=b;
   b->next=c;
   c->next=d;
   d->next=e;
   e->next=f;
   f->next=g;


    display(a);

    Solution s1;
    vector<int> ans=s1.nodesBetweenCriticalPoints(a);
    
 

    for(auto el:ans){
        cout<<el<<" ";
    }
    return 0;
    
}
