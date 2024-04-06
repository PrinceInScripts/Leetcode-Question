/*
Pascal's triangle
*/

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 
 
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> result;

        for(int i=0;i<numRows;i++){
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

        return result;
    }
};


int main(){
    int row;
    cout<<"Enter row number : ";
    cin>>row;

    Solution solution; 
    vector<vector<int>> triangle = solution.generate(row); 
    
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    

    return 0;
}
