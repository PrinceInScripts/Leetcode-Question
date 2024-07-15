

/*
# 165. Compare Version Numbers
*/
/*
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.2", version2 = "1.10"

Output: -1

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:

Input: version1 = "1.01", version2 = "1.001"

Output: 0

Explanation:

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:

Input: version1 = "1.0", version2 = "1.0.0.0"

Output: 0

Explanation:

version1 has less revisions, which means every missing revision are treated as "0".

*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:  
   
    int compareVersion1(string version1, string version2) {
       int idx1=-1,idx2=-1;
       string str1;
       string str2;
       int i=0,j=0;
       int ver1=0,ver2=0;
       while(i<version1.size()){
            if(version1[i]=='.'){
                ver1++;
                int k=i+1;
                while(version1[k]!='.' && k<version1.size()){
                    str1.push_back(version1[k]);
                    k++;
                }
               i=k;
            } else i++;
       }
       while(j<version2.size()){
            if(version2[j]=='.'){
                ver2++;
                int k=j+1;
                while(version2[k]!='.' && k<version2.size()){
                    str2.push_back(version2[k]);
                    k++;
                }
               j=k;
            } else j++;
       }
       
       if(ver1>ver2) {
        int n=(ver1-ver2);
        int p=0;
        while(p<n) {
            str2.push_back('0');
            p++;
        };
       } else if(ver1<ver2) {
        int n=(ver2-ver1);
        int p=0;
        while(p<n){
            str1.push_back('0');
            p++;
        }
       }
   
       
       int num1;
       int num2;

       if(str1.size()==0 && str2.size()==0){
          num1=stoi(version1);
          num2=stoi(version2);
       } else{
       if(str1.size()==0) num1=0;
       else num1=stoi(str1);

       if(str2.size()==0) num2=0;
       else num2=stoi(str2);
       }

       int ans=0;

       if(num1<num2) ans=-1;
       else if(num2<num1) ans=1;
       return ans;

    } 
    int compareVersion(string version1, string version2) {
         vector<int> nums1 = split(version1);
        vector<int> nums2 = split(version2);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int n = max(n1, n2);
        
        for (int i = 0; i < n; ++i) {
            int v1 = i < n1 ? nums1[i] : 0;
            int v2 = i < n2 ? nums2[i] : 0;
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }
        
        return 0;
    } 

private:
    vector<int> split(const string &version) {
        vector<int> nums;
        size_t start = 0;
        size_t end = version.find('.');
        while (end != string::npos) {
            nums.push_back(stoi(version.substr(start, end - start)));
            start = end + 1;
            end = version.find('.', start);
        }
        nums.push_back(stoi(version.substr(start)));
        return nums;
    }
    
   
       
};


int main(){
  string version1="7.5.2.4";
  string version2="7.5.3";
   Solution solution; 
   int ans= solution.compareVersion(version1,version2);

    cout<<ans;
    return 0;
}
