

/*
# 1109. Corporate Flight Bookings
*/
/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

 

Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
Example 2:

Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]
Explanation:
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]

 

Constraints:

1 <= n <= 2 * 104
1 <= bookings.length <= 2 * 104
bookings[i].length == 3
1 <= firsti <= lasti <= n
1 <= seatsi <= 104
 
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int prevLoss=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1) prevLoss+=customers[i];
        }

        int maxLoss=prevLoss;
        int maxIdx=0;
        int i=1;
        int j=minutes;
       
        while(j<n){
            int currLoss=prevLoss;
            if(grumpy[j]==1) currLoss+=customers[j];
            if(grumpy[i-1]==1) currLoss-=customers[i-1];
          
            if(currLoss>maxLoss){
                maxLoss=currLoss;
                maxIdx=i;
            }
            prevLoss=currLoss;
            i++;
            j++;
        }

        for(int i=maxIdx;i<n;i++){
            grumpy[i]=0;
        }

        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }

        return sum;
       
    }
    
   
};


int main(){
   vector<int> customers={1,0,1,2,1,1,7,5};
   vector<int> grumpy={0,1,0,1,0,1,0,1};
   int minutes=3;
 
    Solution solution; 
   int ans=solution.maxSatisfied(customers,grumpy,minutes);

    
    cout<<ans;

    return 0;
}
