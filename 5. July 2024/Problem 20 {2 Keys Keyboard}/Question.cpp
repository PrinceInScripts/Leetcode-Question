

/*
# 650. 2 Keys Keyboard
*/
/*
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

 

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000

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
    int gd1(int n){
        for(int i=n/2;i>1;i--){
            if(n%i==0) return i;
        }
        return 1;
    }
    int gd(int n){
        for(int i=2;i<sqrt(n);i++){
            if(n%i==0) return (n/i);
        }
        return 1;
    }
       
    int minSteps1(int n) {
          int count=0;
          while(n>1){
             int hf=gd(n);
             count+=(n/hf);
             n=hf;
          }
          return count;

    }
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minSteps(int n) {
          int count=0;
          while(n>1){
             if(isPrime(n)){
              count+=n;
              break;
             }
             int hf=gd(n);
             count+=(n/hf);
             n=hf;
          }
          return count;

    }

      
     
    
   
};


int main(){
   int n=3;
  
   Solution solution; 
   int ans=solution.minSteps(n);

    
    cout<<ans;

    return 0;
}
