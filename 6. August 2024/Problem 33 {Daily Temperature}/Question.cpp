

/*
# 739. Daily Temperature
*/
/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:  
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        ans[n-1]=n-1;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && temperatures[st.top()]<=temperatures[i]) st.pop();
            if(st.size()==0) ans[i]=i;
            else ans[i]=st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            ans[i]-=i;
        }
   

        return ans;
    
    }

        
     
};


int main(){
    vector<int> temperature={73,74,75,71,69,72,76,73};
    Solution solution; 
    vector<int> ans= solution.dailyTemperatures(temperature);
    
    for(auto temp:ans){
        cout<<temp<<" ";
    }
    return 0;

}
