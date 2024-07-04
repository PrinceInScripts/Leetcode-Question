

/*
# 2507. Smallest Value After Replacing With Sum of Prime Factors
*/
/*
You are given a positive integer n.

Continuously replace n with the sum of its prime factors.

Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
Return the smallest value n will take on.

 

Example 1:

Input: n = 15
Output: 5
Explanation: Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.
Example 2:

Input: n = 3
Output: 3
Explanation: Initially, n = 3.
3 is the smallest value n will take on.
 

Constraints:

2 <= n <= 105
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
      bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
           if(n%i==0) return false;
        }
        return true;
      }
      
       
      int smallestValue(int n) {
         if(isPrime(n)) return n;
         int sum=0;
         int i=2;
         int m=n;
         while(i<=n){ 
            if(!isPrime(i)) i++;
            if(n%i==0){
                n=n/i;
                if(isPrime(i)) sum+=i;
            } 
            if(n%i!=0) i++;
            
         }
          cout<<sum<<endl;
         cout<<n<<endl;
         if(sum==m) return m;
         else return smallestValue(sum);
      }

      
     
    
   
};


int main(){
 int n=4;
 
    Solution solution; 
   int ans=solution.smallestValue(n);

    
    cout<<ans;

    return 0;
}
