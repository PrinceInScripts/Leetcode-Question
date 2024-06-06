

/*
# 868. Hand of Straights
*/
/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
#include<unordered_map>
using namespace std;

class Solution
{
public:
      
   bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n=hand.size();
     if(n%groupSize!=0) return false;
     
     unordered_map<int,int> nums_map;

     for(int i=0;i<n;i++){
        nums_map[hand[i]]++;
     }

     sort(hand.begin(),hand.end());

     for(auto num:hand){
         if(nums_map[num]==0) continue;

         for(int i=0;i<groupSize;i++){
            if(nums_map[num+i]>0){
                nums_map[num+i]--;
            } else {
                return false;
            }
         }
     }

     return true;

      
      
    }


   

};

int main()
{
   vector<int> arr={3,3,2,2,1,1};  
   int k=3;  

    Solution solution;
    bool ans = solution.isNStraightHand(arr,k);
    
    cout<<ans;
    return 0;
    
}
