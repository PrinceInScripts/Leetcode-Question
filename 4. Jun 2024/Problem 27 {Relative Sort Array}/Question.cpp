

/*
# 1122. Relative Sort Array
*/
/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 
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
      
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> ans;
        vector<int> temp;

        unordered_map<int,int> map;

        for(int i=0;i<arr1.size();i++){
           if(map.find(arr1[i])!=map.end()){
            map[arr1[i]]++;
           } else{
            map[arr1[i]]=1;
           }
        }

        cout<<endl;
        for(int i=0;i<arr2.size();i++){
            if(map.find(arr2[i])!=map.end()){
                int num=arr2[i];
                while(map[num]>0){
                    ans.push_back(arr2[i]);
                    map[num]--;
                }
            }
        }

        for(auto& el:map){
            while(el.second>0){
                temp.push_back(el.first);
                el.second--;
            }
        }

        sort(temp.begin(),temp.end());

         for(int i=0;i<temp.size();i++){
           ans.push_back(temp[i]);
        }

        return ans;
        
       
    }


   

};

int main()
{
//    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19};   
//    vector<int> arr2={2,1,4,3,9,6};   
   vector<int> arr1={2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31};   
   vector<int> arr2={2,42,38,0,43,21};   

    Solution solution;
    vector<int> ans = solution.relativeSortArray(arr1,arr2);
    
    for(int el:ans){
        cout<<el<<" ";
    }
    return 0;
    
}
