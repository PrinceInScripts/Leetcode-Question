

/*
# 505. Perfect Square
*/
/*
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false
 

Constraints:

1 <= num <= 108
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
using namespace std;

class Solution {
public:   
     
       
      bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<sqrt(num);i++){
             if(num%i==0) sum+=i;
        }
        for(int i=sqrt(num);i>1;i--){
             if(num%i==0) sum+=(num/i);
        }
        if(num==sum) return true;
        else return false;
    }

      
     
    
   
};


int main(){
  int num=28;
    Solution solution; 
   bool ans=solution.checkPerfectNumber(num);

    
    cout<<ans;

    return 0;
}
