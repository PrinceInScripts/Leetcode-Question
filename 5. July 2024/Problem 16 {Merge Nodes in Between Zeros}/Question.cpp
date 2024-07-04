

/*
# 2181.Merge Nodes in Between Zeros
*/
/*

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<regex>
using namespace std;
 struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
      
class Solution {
public:   
        

      ListNode* mergeNodes(ListNode* head) {
         ListNode* current=head->next;
         ListNode* result=current;
         ListNode* nextSum=current;
         
         while(nextSum != nullptr){
            int sum=0;
            while(nextSum->val != 0){
                sum+=nextSum->val;
                nextSum=nextSum->next;
            }
            result->val=sum;
            nextSum=nextSum->next;
            result->next=nextSum;
            result=result->next;
         }

         return head->next;


      }

     

      
     
    
   
};


int main(){
   vector<int> head={0,3,1,0,4,5,2,0};
    Solution solution;

    // Convert vector to linked list
    ListNode* head_list = nullptr;
    ListNode** head_tail = &head_list;
    for (int x : head) {
        (*head_tail)->next = new ListNode(x);
        (*head_tail) = (*head_tail)->next;
    }

    // Call mergeNodes function
    ListNode *ans = solution.mergeNodes(head_list);

    // Print result
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;

}
