

/*
# 231.  Power of two
*/
/*

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
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
   
    bool isPowerOfTwo(int n) {
         if(((n)&(n-1))==0) return true;
         else return false;
    }
    
    
    
   
};


int main(){
   int n=3;
 
    Solution solution; 
    bool ans=solution.isPowerOfTwo(n);

    
    cout<<ans;

    return 0;
}
