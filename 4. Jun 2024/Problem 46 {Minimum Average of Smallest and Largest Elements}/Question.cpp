

/*
# 100342.  Minimum Average of Smallest and Largest Elements
*/
/*
You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
You repeat the following procedure n / 2 times:
•	Remove the smallest element, minElement, and the largest element maxElement, from nums.
•	Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.
 
Example 1:
Input: nums = [7,8,3,4,15,13,4,1]
Output: 5.5
Explanation:
step	nums	averages
0	[7,8,3,4,15,13,4,1]	[]
1	[7,8,3,4,13,4]	[8]
2	[7,8,4,4]	[8,8]
3	[7,4]	[8,8,6]
4	[]	[8,8,6,5.5]
The smallest element of averages, 5.5, is returned.
Example 2:
Input: nums = [1,9,8,3,10,5]
Output: 5.5
Explanation:
step	nums	averages
0	[1,9,8,3,10,5]	[]
1	[9,8,3,5]	[5.5]
2	[8,5]	[5.5,6]
3	[]	[5.5,6,6.5]
Example 3:
Input: nums = [1,2,3,7,8,9]
Output: 5.0
Explanation:
step	nums	averages
0	[1,2,3,7,8,9]	[]
1	[2,3,7,8]	[5]
2	[3,7]	[5,5]
3	[]	[5,5,5]

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
    double minimumAverage(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      vector<double> temp;
      int i=0,j=nums.size()-1;
      while(i<=j){
        double num=(nums[i]+nums[j])/2.0;
        temp.push_back(num);
        i++;
        j--;
      }
      
      return *min_element(temp.begin(), temp.end());
    }
   
    
   
};

int main()
{
// vector<int> nums={7,8,3,4,15,13,4,1};
vector<int> nums={1,2,3,7,8,9};


    Solution solution;
    double ans = solution.minimumAverage(nums);
   
    cout<<ans;
    return 0;
    
}
