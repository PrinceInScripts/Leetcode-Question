

/*
# 204. Count Primes
*/
/*
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
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
      void fillSieve(vector<int>& sieve){
            int n=sieve.size()-1;
            for(int i=2;i<=sqrt(n);i++){
                for(int j=i*2;j<=n;j+=i){
                    sieve[j]=0;
                }
            }
      }
       
      int countPrimes(int n) {
       if(n<=2) return 0;
        n=n-1;
        int count=0;
        vector<int> sieve(n+1,1);
        fillSieve(sieve);
        for(int i=2;i<=n;i++){
          if(sieve[i]==1) count++;
        }
        return count;

    }

      
     
    
   
};


int main(){
  int num=3;
    Solution solution; 
   int ans=solution.countPrimes(num);

    
    cout<<ans;

    return 0;
}
