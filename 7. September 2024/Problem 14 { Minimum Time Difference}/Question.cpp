

/*
# 539.  Minimum Time Difference
*/
/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include <limits.h>
#include<cmath>
using namespace std;

class Solution
{
public:
  
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
       for(auto time:timePoints){
           int min=(time[3]-48)*10+time[4]-48;
           int hr=(time[0]-48)*10+time[1]-48;
           int minute=hr*60+min;
           
           minutes.push_back(minute);
       }
       sort(minutes.begin(),minutes.end());
        int minDiff = INT_MAX;
        for (int i=1;i<minutes.size();i++) {
            minDiff=min(minDiff,minutes[i]-minutes[i-1]);
        }

        int midDiff=1440+minutes[0]-minutes[minutes.size()-1];
        minDiff=min(minDiff,midDiff);
       return minDiff;
       
    }
   

};

int main()
{
   vector<string> timePoints={"00:00","23:59"};
  
    

    Solution solution;
   int ans = solution.findMinDifference(timePoints);

  cout<<ans;
    return 0;
    
}
