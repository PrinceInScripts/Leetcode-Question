

/*
# 4. Sum in a matrix
*/
/*
You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:

From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
Identify the highest number amongst all those removed in step 1. Add that number to your score.
Return the final score.

 

Example 1:

Input: nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
Output: 15
Explanation: In the first operation, we remove 7, 6, 6, and 3. We then add 7 to our score. Next, we remove 2, 4, 5, and 2. We add 5 to our score. Lastly, we remove 1, 2, 3, and 1. We add 3 to our score. Thus, our final score is 7 + 5 + 3 = 15.
Example 2:

Input: nums = [[1]]
Output: 1
Explanation: We remove 1 and add it to the answer. We return 1.
 

Constraints:

1 <= nums.length <= 300
1 <= nums[i].length <= 500
0 <= nums[i][j] <= 103
*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
     
    int matrixSum(vector<vector<int>>& nums) {
           int row=nums.size();
           int col=nums[0].size();
           vector<int> temp;
           int sum=0;
           for(int i=0;i<row;i++){
            int max=INT_MIN;
            for(int j=0;j<col;j++){
                 if(nums[i][j]>max){
                    max=nums[i][j];
                 }
                 
            }
            temp.push_back(max);
           }
           for(int el:temp){
            cout<<el<<" ";
            sum+=el;
           }
           cout<<endl;

           return sum;
        
    }
};


int main(){
    // vector<vector<int>> nums = {{1,8,16,15,12,9,15,11,18,6,16,4,9,4},
    //                            {3,19,8,17,19,4,9,3,2,10,15,17,3,11},
    //                            {3,10,19,20,6,17,15,14,16,8,1,17,0,2},
    //                            {12,20,0,19,15,10,7,10,2,6,18,7,7,4},
    //                            {17,14,2,2,10,16,15,3,9,17,9,3,17,10},
    //                            {17,6,19,17,18,9,14,2,19,12,10,18,7,9},
    //                            {5,6,5,1,19,8,15,2,2,4,4,1,2,17},
    //                            {12,16,8,16,7,6,18,13,18,8,14,15,20,11},
    //                            {2,10,19,3,15,18,20,10,6,7,0,8,3,7},
    //                            {11,5,10,13,1,3,4,7,1,18,20,17,19,2},
    //                            {0,3,20,6,19,18,3,12,2,11,3,1,19,0},
    //                            {6,5,3,15,6,1,0,17,13,19,3,8,2,7},
    //                            {2,20,9,11,13,5,1,16,14,1,19,3,12,6},
                              
    //                             };
    vector<vector<int>> nums = {{7,2,1},
                               {6,4,2},
                               {6,5,3},
                               {3,2,1}
                              
                                };
   
    
    Solution solution; 
    int sum=solution.matrixSum(nums);

    
    cout<<sum << endl;

    return 0;
}
