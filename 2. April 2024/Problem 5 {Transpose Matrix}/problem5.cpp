/*
# 867. Transpose Matrix
*/
/*
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.



 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
      
     
      vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        cout<<row<<" "<<col<<endl;
        
        vector<vector<int>> t(col,vector<int>(row));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                t[i][j]=matrix[j][i];
            }
        }
        
        return t;
       
    }
};


int main(){
     vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Solution solution; 
    vector<vector<int>> result = solution.transpose(nums);

    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
