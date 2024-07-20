

/*
# 3132. Find the Integer Added to Array II
*/
/*
You are given two integer arrays nums1 and nums2.

From nums1 two elements have been removed, and all other elements have been increased (or decreased in the case of negative) by an integer, represented by the variable x.

As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

Return the minimum possible integer x that achieves this equivalence.

 

Example 1:

Input: nums1 = [4,20,16,12,8], nums2 = [14,18,10]

Output: -2

Explanation:

After removing elements at indices [0,4] and adding -2, nums1 becomes [18,14,10].

Example 2:

Input: nums1 = [3,5,5,3], nums2 = [7,7]

Output: 2

Explanation:

After removing elements at indices [0,3] and adding 2, nums1 becomes [7,7].

 

Constraints:

3 <= nums1.length <= 200
nums2.length == nums1.length - 2
0 <= nums1[i], nums2[i] <= 1000
The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by removing two elements and adding x to each element of nums1.

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
    int minimumAddedInteger1(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto el:nums1){
            cout<<el<<" ";
        }
        cout<<endl;
        nums1.erase(nums1.begin(),nums1.begin()+2);
        for(auto el:nums1){
            cout<<el<<" ";
        }
        cout<<endl;
        for(auto el:nums2){
            cout<<el<<" ";
        }
        cout<<endl;

        int count=1;
        int ans=nums2[0]-nums1[0];
        for(int i=1;i<nums1.size();i++){
            if((nums2[i]-nums1[i])==ans) count++;
        }
        if(count==nums1.size()) return ans;
        else return 0;
    }    
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n=nums1.size(),m=nums2.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> temp;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        temp.push_back(nums1[k]);
                    }
                }

                int x=nums2[0]-temp[0];
                bool flag=true;

                for(int k=0;k<m;k++){
                    if(nums2[k] != temp[k]+x){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    ans=min(ans,x);
                }
            }
        }
        return ans;
    }    
};


int main(){
//    vector<int> nums1={4,6,3,1,4,2,10,9,5};
   vector<int> nums1={4,20,16,12,8};
//    vector<int> nums2={5,10,3,2,6,1,9};
   vector<int> nums2={14,18,10};
   Solution solution; 
   int ans= solution.minimumAddedInteger(nums1,nums2);

    cout<<ans;
    return 0;
}
