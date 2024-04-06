/*
119. Pascal's triangle 2
*/

/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 
 
 
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
     vector<int> getRow(int rowIndex) {
        int m=rowIndex+1;
        vector<vector<int>> result;

        for(int i=0;i<m;i++){
            vector<int> a(i+1);
            result.push_back(a);
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    result[i][j]=1;
                }else {
                   result[i][j]=result[i-1][j]+result[i-1][j-1];
                }
            }
        }

        return result[rowIndex];
    }
};


int main(){
    int row;
    cout<<"Enter row number : ";
    cin>>row;

    Solution solution; 
    vector<int> triangle = solution.getRow(row); 
    
   
        for (int num : triangle) {
            cout << num << " ";
        }
        cout << endl;
    
    

    return 0;
}
