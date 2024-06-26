/*
# 74. Search a 2D matrix
*/
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row=matrix.size();
        int col=matrix[0].size();
        bool flag=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==target){
                    flag=true;
                    break;
                }
            }
        }

        return flag;
        
    }
};


int main(){
    vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    
    Solution solution; 
    int score=solution.searchMatrix(nums,target);

    
    cout<<score << endl;

    return 0;
}
