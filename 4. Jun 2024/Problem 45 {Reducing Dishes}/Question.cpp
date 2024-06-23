

/*
# 1402.  Reducing Dishes
*/
/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
*/

#include <iostream>
#include <vector> 
#include<algorithm>
#include <limits.h>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    int maxSatisfaction1(vector<int>& satisfaction) {
      int n=satisfaction.size();
      int mx=INT_MIN;
      sort(satisfaction.begin(),satisfaction.end());
      for(int i=0;i<n;i++){
        int mxSum=0;
        int k=1;
        for(int j=i;j<n;j++){
           mxSum+=satisfaction[j]*k;
           k++;
        }
        mx=max(mx,mxSum);
      }
      if(mx<0) return 0;
      else return mx;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
      int n=satisfaction.size();
      int idx=-1;

      sort(satisfaction.begin(),satisfaction.end());
      int suffixSum[n];

      suffixSum[n-1]=satisfaction[n-1];
      for(int i=n-2;i>=0;i--){
        suffixSum[i]=suffixSum[i+1]+satisfaction[i];
      }

      for(int i=0;i<n;i++){
       if(suffixSum[i]>=0){
        idx=i;
         break;
       }
      }

      if(idx==-1) return 0;
      int maxSum=0;
      int k=1;
      for(int i=idx;i<n;i++){
        maxSum+=(satisfaction[i]*k);
        k++;
      }
      return maxSum;
     
    }
    
   
};

int main()
{
//   vector<int> satisfaction ={4,3,2};
  vector<int> satisfaction ={-1,-8,0,5,-9};
//   vector<int> satisfaction ={-1,-4,-5};

    Solution solution;
    int ans = solution.maxSatisfaction(satisfaction);
   
    cout<<ans;
    return 0;
    
}
