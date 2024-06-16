/*
# 204. Search a 2D matrix
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
        int i=0;
        int j=col-1;
        while(i<=row-1 && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }

        return false;
        
    }
};


int main(){
    vector<vector<int>> nums = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    
    Solution solution; 
    int score=solution.searchMatrix(nums,target);

    
    cout<<score << endl;

    return 0;
}
