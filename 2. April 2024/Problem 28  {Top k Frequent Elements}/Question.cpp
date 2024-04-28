

/*
# 347. Top K Frequent elements
*/
/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
   /*   //  vector<int> topKFrequent(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<vector<int>> elements;
    //     vector<int> copyNums=nums;

    //     vector<bool> visited(n,false);

    //     for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //         vector<int> element={nums[i]};
    //         int count=1;
    //         visited[i]=true;
            

    //         for(int j=i+1;j<n;j++){
    //             if(!visited[j] && nums[i]==nums[j]){
    //                 count++;
    //                 visited[j]=true;
    //             }
    //         }
    //         element.push_back(count);
    //         elements.push_back(element);
    //         }
    //     }

    //     for(int i=0;i<elements.size();i++){
    //         for(int j=0;j<elements[0].size();j++){
    //             cout<<elements[i][j]<<" ";
            
    //         }
    //         cout<<endl;
    //     }
        
       
    //     for (int i = 0; i < elements.size() - 1; ++i) {
    //         for (int j = 0; j < elements.size() - i - 1; ++j) {
    //             if (elements[j][1] < elements[j + 1][1]) {
    //                 swap(elements[j], elements[j + 1]);
    //             }
    //         }
    //     }
    //     cout<<"-----------------";

    //     for(int i=0;i<elements.size();i++){
    //         for(int j=0;j<elements[0].size();j++){
    //             cout<<elements[i][j]<<" ";
            
    //         }
    //         cout<<endl;
    //     }
        

      
    //     vector<int> ans;
    //     for(int i=0;i<k;i++){
    //         ans.push_back(elements[i][0]);
    //     }
        
        
    //     return ans;

    // }

    */
     
     vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        vector<pair<int,int>> freq;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
              count++;
            } else {
                freq.push_back({nums[i-1],count});
                count=1;
            }
        }
for (const auto& p : freq) {
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}
        freq.push_back({nums.back(),count});
        
       sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freq[i].first); 
        }
        
        return result;
    }

};

int main()
{
    vector<int> nums = {4,1,-1,2,-1,2,3};
    int k=2;

    Solution solution;
    vector<int> ans = solution.topKFrequent(nums,k);

    for(int num:ans){
        cout<<num<<" ";
    }

    return 0;
}
