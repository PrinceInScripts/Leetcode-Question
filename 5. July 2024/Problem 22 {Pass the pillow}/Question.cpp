

/*
# 2582. Pass the Pillow
*/
/*
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.

 

Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.
 

Constraints:

2 <= n <= 1000
1 <= time <= 1000

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
      int passThePillow(int n, int time) {
           if(time < n) return time+1;
        n = n-1;
        int count = 0;
        while(time >= n){
            count++;
            time = time-n;
        }
        if(count % 2 == 0) return time+1;
        else return n-time+1;

      } 
};


int main(){
   int n=3;
   int t=2;
  
   Solution solution; 
   int ans=solution.passThePillow(n,t);

    
    cout<<ans;

    return 0;
}