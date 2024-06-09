

/*
# 633. Sum of Square Number
*/
/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<cmath>
using namespace std;

class Solution
{
public:
   bool isSquareRoot(int n){
       int root=sqrt(n);

       if((root*root)==n) return true;
       else false;
   }
      
   bool judgeSquareSum1(int c) {
      int x=0;
      int y=c;

      while(x<=y){
        if(isSquareRoot(x) && isSquareRoot(y)){
            return true;
        }
        x++;
        y--;
      }
      
      return false;
    }
   bool judgeSquareSum(int c) {
      int x=0;
      int y=c;

      while(x<=y){
        if(isSquareRoot(x) && isSquareRoot(y)){
            return true;
        } else if(!isSquareRoot(y)){
            y=(int)sqrt(y)*(int)sqrt(y);
            x=c-y;
        } else if(!isSquareRoot(x)){
            x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
            y=c-x;
        }
      }
      
      return false;
    }


   

};

int main()
{
   int n=41;  

    Solution solution;
    bool ans = solution.judgeSquareSum(n);
    
    cout<<ans;
    return 0;
    
}
