

/*
# 1648. Sort Array by Increasing Frequency
*/
/*
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 
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
#include<queue>
using namespace std;

class Solution {
public:         
     vector<int> frequencySort1(vector<int>& nums) {
            unordered_map<int,int> numFreq;
            unordered_set<int> freq;
            vector<int> ans;

            sort(nums.begin(),nums.end());
            int i=1;
            int count=1;
            while(i<nums.size()){
                if(nums[i]!=nums[i-1]){
                    numFreq[nums[i-1]]=count;
                    freq.insert(count);
                    count=1;
                } else {
                    count++;
                }
                i++;
            }
            numFreq[nums[i-1]]=count;
            freq.insert(count);
            
            vector<int> v(freq.begin(), freq.end());
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++){
                vector<int> temp;
                for(auto& el:numFreq){
                    if(el.second==v[i]){
                       temp.push_back(el.first);
                    }
                }

                sort(temp.begin(),temp.end(),greater<int>());

                for(int p=0;p<temp.size();p++){
                    for(int q=0;q<v[i];q++){
                        ans.push_back(temp[p]);
                    }
                }
            }

           return ans;
      }
     vector<int> frequencySort(vector<int>& nums) {
            unordered_map<int,int> freq;
           for(auto el:nums){
               freq[el]++;
           }

           for(auto& el:freq){
            cout<<el.first<<" "<<el.second<<endl;
           }
            
           priority_queue<pair<int,int>> pq;
           
           for(const auto& p:freq){
               pq.push({-p.second,p.first});
           }
           vector<int> ans;
           while(pq.size()>0){
            int f=-pq.top().first;
            int s=pq.top().second;
            while(f>0){
                ans.push_back(s);
                f--;
            }
            pq.pop();
           }
           

           return ans;
      }
        
};


int main(){
//   vector<int> nums={-1,1,-6,4,5,-6,1,4,1};
  vector<int> nums={2,3,1,3,2};
   Solution solution; 
  vector<int> ans= solution.frequencySort(nums);

  for(auto el:ans){
    cout<<el<<" ";
  }
  return 0;

}
