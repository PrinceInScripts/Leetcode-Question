/*
# 15.3 Sum
*/
/*
GGiven an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
      
      bool isExist(vector<vector<int>> nums,vector<int> a){
        for(int i=0;i<nums.size();i++){
            vector<int> arr={nums[i]};
            int count=0;
            bool flag=false;
            for(int j=0;j<a.size();j++){
                if(arr[j]==a[j]){
                   count++;
                }
            }

            if(count==a.size()){
                flag=true;
            }

            return flag;
        }
      }
      vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>> result;
       sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           
            for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                     vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(nums[k]);
                    if(!isExist(result,a)){
                       result.push_back(a);
                    }
                }
               }
            }
        }
        return result;
    }
};


int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    
    Solution solution; 
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
