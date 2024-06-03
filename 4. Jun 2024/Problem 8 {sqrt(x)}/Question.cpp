

/*
# 69. Sqrt(x)
*/
/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x) {
      int lo=0;
      int hi=x;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if((long long)(mid*mid)==(long long)x) return mid;
        else if((long long)(mid*mid)>(long long)x) hi=mid-1;
        else if((long long)(mid*mid)<(long long)x) lo=mid+1;
      }

      return hi;
      
    }
   

};

int main()
{
   int x=20;
    

    Solution solution;
    int ans = solution.mySqrt(x);
    cout<<ans;

    return 0;
    
}
