

/*
# 658. Find K Closest Elements
*/
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int n=arr.size();
      vector<int> ans(k);

      //when x < arr[0]
      if(x<arr[0]){
        for(int i=0;i<k;i++){
          ans[i]=arr[i];
        }
        return ans;
      }

      //when x > arr[0]
      if(x>arr[n-1]){
        int i=n-1;
        int j=k-1;
        while(j>=0){
            ans[j]=arr[i];
            i--;
            j--;
        }
        return ans;
      }

      //when x is on array 
      int lo=0;
      int hi=n-1;
      bool flag=false;
      int idx=0;
      int mid=-1;
      while(lo<=hi){
        mid=lo+(hi-lo)/2;

        if(arr[mid]==x){
           flag=true;
           ans[idx]=x;
           idx++;
           break;
        }
        else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
      }
      cout<<hi<<endl;
      cout<<lo<<endl;

      int lb=hi;
      int hb=lo;
      if(flag){
        lb=mid-1;
        hb=mid+1;
      }

      while(idx<k && lb>=0 && hb<=n-1){
        int d1=abs(x-arr[lb]);
        int d2=abs(x-arr[hb]);
        
        if(d1<=d2){
            ans[idx]=arr[lb];
            lb--;
        } else {
            ans[idx]=arr[hb];
            hb++;
        }
        idx++;
      }

      if(lb<0){
        while(idx<k){
           ans[idx]=arr[hb];
           hb++;
           idx++;
        }
      } 
      if(hb>n-1){
        while(idx<k){
            ans[idx]=arr[lb];
            lb--;
            idx++;
        }
      }
      sort(ans.begin(),ans.end());
      return ans;


      
    }
   

};

int main()
{
   vector<int> arr={0,0,1,2,3,3,4,7,7,8};
   int k=3;
   int x=5;
    

    Solution solution;
    vector<int> ans = solution.findClosestElements(arr,k,x);
    
    for(auto& el:ans){
        cout<<el<<endl;
    }
    return 0;
    
}
