

/*
# 3169.  Count Days Without Meetings
*/
/*
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.

 

Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
 

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
    
    int countDays1(int days, vector<vector<int>>& meetings) {
       int n=meetings.size();
       unordered_set<int> nums;
   
       int count=0;
   
       for(int i=0;i<n;i++){
         int x=meetings[i][0];
         int y=meetings[i][1];
    
         while(x<=y){
           nums.insert(x);
            x++;
         }
       }

   
    return days-nums.size();
    }    
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

       int start=meetings[0][0];
       int end=meetings[0][1];

       for(int i=1;i<meetings.size();i++){
        if(meetings[i][0]<=end){
            end=max(end,meetings[i][1]);
        } else{
            days-=end-start+1;
            start=meetings[i][0];
            end=meetings[i][1];
        }
       }
         days-=end-start+1;

         return days;
    }    
};


int main(){
  int days=6;
//   vector<vector<int>> meetings={{5,7},{1,3},{9,10}};
  vector<vector<int>> meetings={{1,6}};
//   vector<vector<int>> meetings={{2,4},{1,3}};
   Solution solution; 
   int ans= solution.countDays(days,meetings);

    cout<<ans;
    return 0;
}
