

/*
# 875. Koko Eating Bananas
*/
/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    bool check(int speed,vector<int>& piles,int h){
           int n=piles.size();
           int m=speed;
           int count=0;

           for(int i=0;i<n;i++){
              if(count>h) return false;
              if(speed>=piles[i]) count++;
              else if(piles[i]%speed==0) count+=piles[i]/speed;
              else count+=piles[i]/speed+1;
           }

           if(count<=h) return true;
           else return false;
    }
    bool check1(int mid,vector<int>& piles,int h){
           int n=piles.size();
           int m=mid;
           int count=0;

           for(int i=0;i<n;i++){
            int k=piles[i];

            
             while(k>=0){
                k-=m;
                count++;
                if(k<=0){
                    break;
                }
             }
           }

           if(count<=h) return true;
           else return false;
    }
      
    int minEatingSpeed(vector<int>& piles, int h) {
      int n=piles.size();
      int max=INT_MIN;

      for(int i=0;i<n;i++){
        if(piles[i]>max) max=piles[i];
      }

      int lo=1;
      int hi=max;
      int ans=-1;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(mid,piles,h)){
              ans=mid;
              hi=mid-1;
        } else{
            lo=mid+1;
        }
      }

      return ans;
    }


   

};

int main()
{
  vector<int> piles={30,11,23,4,20};  
  int h=6;

    Solution solution;
    int ans = solution.minEatingSpeed(piles,h);
    
    cout<<ans;
    return 0;
    
}
