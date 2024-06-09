

/*
# 2187. Minimum Time to Complete Trips
*/
/*

You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 

Example 1:

Input: time = [1,2,3], totalTrips = 5
Output: 3
Explanation:
- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  The total number of trips completed is 1 + 0 + 0 = 1.
- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  The total number of trips completed is 2 + 1 + 0 = 3.
- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  The total number of trips completed is 3 + 1 + 1 = 5.
So the minimum time needed for all buses to complete at least 5 trips is 3.
Example 2:

Input: time = [2], totalTrips = 1
Output: 2
Explanation:
There is only one bus, and it will complete its first trip at t = 2.
So the minimum time needed to complete 1 trip is 2.
 
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    bool check(long long mid,vector<int>& time,int totalTrips){
          int n=time.size();
          long long trips=0;

          for(int i=0;i<n;i++){
            trips+=mid/(long long)time[i];
          }

          if(trips<(long long)totalTrips) return false;
          else return true;
    }
      
    long long minimumTime(vector<int>& time, int totalTrips) {
      int n=time.size();
      int mx=INT_MIN;

      for(int i=0;i<n;i++){
        mx=max(mx,time[i]);
      }

      long long lo=1;
      long long hi=((long long)mx*(long long)totalTrips);
      long long ans=-1;

      while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(mid,time,totalTrips)){
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
  vector<int> time={9,7,10,9,10,9,10};  
  int totalTrips=1;

    Solution solution;
    long long ans = solution.minimumTime(time,totalTrips);
    
    cout<<ans;
    return 0;
    
}
