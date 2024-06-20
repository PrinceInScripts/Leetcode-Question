

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
#include<unordered_set>
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
   bool judgeSquareSum2(int c) {
      int i=0;
      int j=(int)sqrt(c);

      while(i<=j){
         int sum=i*i+j*j;
         if(sum==c) return true;
         else if(sum<c) i++;
         else j--;
      }
      return false;
    }
   bool judgeSquareSum3(int c) {
      unordered_set<int> squares;

      int max=(long)sqrt(c);

      for(int i=0;i<=max;i++){
        squares.insert(i*i);
      }

      for(int i=0;i<=max;i++){
       if(squares.count(c-i*i)) return true;

      }
      return false;
    }
    


   

};

int main()
{
   int n=41;  

    Solution solution;
    bool ans = solution.judgeSquareSum(n);
    bool ans1 = solution.judgeSquareSum2(n);
    bool ans2 = solution.judgeSquareSum3(n);
    
    cout<<ans<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
    
}
