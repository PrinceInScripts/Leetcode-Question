

/*
# 268. Missing Element
*/
/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
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
   
  int missingNumber1(vector<int>& nums) {
        int n=nums.size();
        vector<bool> check(n+1,false);

        for(int i=0;i<n;i++){
           int el=nums[i];
           check[el]=true;
        }

        for(int i=0;i<=n;i++){
            if(check[i]==false) return i;
        }
        return -1;
}
  int missingNumber2(vector<int>& nums) {
        int n=nums.size();
        int actualSum=n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return (actualSum-sum);
}
  int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctIdx=nums[i];
            if(i==correctIdx || nums[i]==n) i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++){
            if(i!=nums[i]) return i;
        }
        return n;
}


   

};

int main()
{
    vector<int> nums={0,1};

    Solution solution;
    int ans = solution.missingNumber(nums);
    int ans1 = solution.missingNumber1(nums);
    int ans2 = solution.missingNumber2(nums);
    
    cout<<ans<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
    
}
