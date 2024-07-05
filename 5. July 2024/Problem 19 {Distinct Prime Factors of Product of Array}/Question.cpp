

/*
# 2521. Distinct Prime Factors of Product of Array
*/
/*
Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

Note that:

A number greater than 1 is called prime if it is divisible by only 1 and itself.
An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
 

Example 1:

Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.
Example 2:

Input: nums = [2,4,8,16]
Output: 1
Explanation:
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.
 

Constraints:

1 <= nums.length <= 104
2 <= nums[i] <= 1000

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
      void fillSieve(vector<bool>& sieve){
        int n=sieve.size();
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<=n;j+=i){
                 sieve[j]=0;
            }
        }
      }
      int distinctPrimeFactors1(vector<int>& nums) {
           int n=nums.size();
           
           //Find out MAX value on array
           int mx=INT_MIN;
           for(int i=0;i<n;i++){
             mx=max(mx,nums[i]);
           }

           //create sieve for getting limits of primes
           vector<bool> sieve(mx+1,1);
           fillSieve(sieve);

           //set all primes num related array
           vector<int> primes;
           for(int i=0;i<sieve.size();i++){ 
               if(i<=1) continue;
               if(sieve[i]==1){
                primes.push_back(i);
               }
           }

           //count use primes num
           vector<bool> taken(primes.size(),false);
           for(int i=0;i<n;i++){
            for(int j=0;j<primes.size();j++){
                if(nums[i]%primes[j]==0){
                    taken[j]=true;
                }
            }
          }
          int count=0;
          for(auto el:taken){
              if(el) count++;
          }

          return count;

    }
      int distinctPrimeFactors(vector<int>& nums) {
           int n=nums.size();
           
           //Find out MAX value on array
           int mx=INT_MIN;
           for(int i=0;i<n;i++){
             mx=max(mx,nums[i]);
           }

           //create sieve for getting limits of primes
           vector<bool> sieve(mx+1,1);
           if(mx+1>0) sieve[0]=0;
           if(mx+1>1) sieve[1]=0;
           fillSieve(sieve);

           //set all primes num related array
           vector<int> primes;
           for(int i=2;i<sieve.size();i++){ 
               if(sieve[i]==1){
                primes.push_back(i);
               }
           }

           //count use primes num
           vector<bool> taken(primes.size(),false);
           for(int i=0;i<n;i++){
             int el=nums[i];
            for(int j=0;j<primes.size();j++){
                if(primes[j]>el) break;
                if(el%primes[j]==0){
                    taken[j]=true;
                }
            }
          }
          int count=0;
          for(auto el:taken){
              if(el) count++;
          }

          return count;

    }

      
     
    
   
};


int main(){
   vector<int> nums={2,4,8,16};
  
   Solution solution; 
   int ans=solution.distinctPrimeFactors(nums);

    
    cout<<ans;

    return 0;
}
