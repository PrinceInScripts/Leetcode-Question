

/*
# 121. Best Time to Buy and Sell Stock
*/
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices) {
      int min=INT_MAX;
      int max=INT_MIN;
      int idx=-1;

      for(int i=0;i<prices.size();i++){
        if(prices[i]<min){
           min=prices[i];
           idx=i;
        }
      }

      if(idx==prices.size()) return 0;
      
      for(int i=idx;i<prices.size();i++){
        if(prices[i]>max){
           max=prices[i];
        }
      }

     int ans=max-min;
      return ans;
      

      
    }
   

};

int main()
{
   vector<int> arr={7,1,5,3,6,4};    

    Solution solution;
    int ans = solution.maxProfit(arr);
    
    cout<<ans;
    return 0;
    
}
