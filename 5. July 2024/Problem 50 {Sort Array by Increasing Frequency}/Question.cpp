

/*
# 2191. Sort the Jumbled Numbers
*/
/*
GYou are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 

Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109

 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:     
     vector<int> distributeNum(int num){
         string s=to_string(num);
          vector<int> st;
          for(int i=0;i<s.size();i++){
            st.push_back(s[i] - '0'); 
          }

          return st;

     }    
     vector<int> sortJumbled1(vector<int>& mapping, vector<int>& nums) {
          vector<int> mapNums(nums.size());
         
          for(int i=0;i<nums.size();i++){
             vector<int> disNum=distributeNum(nums[i]);
             int s=0;
             for(int el:disNum){
               s=s*10+mapping[el];
             }

           mapNums[i]=s;
            
          }
         
          for(int i=0;i<mapNums.size();i++){
            for(int j=i+1;j<mapNums.size();j++){
                if(mapNums[i]>mapNums[j]){
                    swap(nums[i],nums[j]);
                    swap(mapNums[i],mapNums[j]);
                }
            }
          }

         return nums;
      }
     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
          
          vector<pair<int,int>> numPairs;
         
          for(int i=0;i<nums.size();i++){
             vector<int> disNum=distributeNum(nums[i]);
             int s=0;
             for(int el:disNum){
               s=s*10+mapping[el];
             }
            numPairs.push_back({s,i});
          }
         
          stable_sort(numPairs.begin(),numPairs.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first<b.first;
          });
        

          vector<int> sortedNums;
          for(auto& el:numPairs){
            sortedNums.push_back(nums[el.second]);
          }

         return sortedNums;
      
      }
        
};


int main(){
  vector<int> mappings={8,9,4,0,2,1,3,5,7,6};
  vector<int> nums={991,338,38};
   Solution solution; 
  vector<int> ans= solution.sortJumbled(mappings,nums);

  for(auto el:ans){
    cout<<el<<" ";
  }
  return 0;

}
