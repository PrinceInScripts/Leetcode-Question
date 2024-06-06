

/*
# 1296. Divide Array in Sets of K Consecutive Numbers
*/
/*
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.

 
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
      
   bool isPossibleDivide(vector<int>& nums, int k) {
      int n=nums.size();

      if(n%k==0){
        unordered_map<int,int> nums_map;

        for(int i=0;i<nums.size();i++){
            nums_map[nums[i]]=i;
        }
        
        for(int i=0;i<=n/k;i++){
            int min=INT_MAX;

            for(auto& el:nums_map){
                cout<<min<<endl;
                if(el.first>min){
                    min=el.first;
                }
            }
            cout<<min<<endl;

            nums_map.erase(min);
            if(nums_map.find(min+1) != nums_map.end() && nums_map.find(min+2) != nums_map.end()){
                nums_map.erase(min+1);
                nums_map.erase(min+2);
            } else{
                return false;
            }
        }

        return true;
      }
      else return false;
      
      
    }


   

};

int main()
{
   vector<int> arr={1,2,3,3,4,4,5,6};  
   int k=4;  

    Solution solution;
    bool ans = solution.isPossibleDivide(arr,k);
    
    cout<<ans;
    return 0;
    
}
