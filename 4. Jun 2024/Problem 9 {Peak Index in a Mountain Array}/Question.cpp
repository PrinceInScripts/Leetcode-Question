

/*
# 852. Peak Index in a Mountain Array
*/
/*
An array arr is a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1
 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int lo=1;
      int hi=arr.size()-2;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
            lo=mid+1;
        } else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
            hi=mid+1;
        }
        
      }

      
    }
    int peakIndexInMountainArray1(vector<int>& arr) {
      int lo=1;
      int hi=arr.size()-2;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid]>arr[mid+1] ) hi=mid-1;
        else lo=mid+1;
        
      }

      
    }
   

};

int main()
{
   vector<int> nums={1,2,3,5,4,3,2};
    

    Solution solution;
   int ans = solution.peakIndexInMountainArray(nums);
    cout<<ans<<endl;
   int ans1 = solution.peakIndexInMountainArray1(nums);
    cout<<ans1;

    return 0;
    
}
