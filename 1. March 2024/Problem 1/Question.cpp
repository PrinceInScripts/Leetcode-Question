/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
*/

#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == INT_MIN) return 0;
         if(x<0){
            return false;
         }

         int reverse=0,y=x;
         
         while(y>0){
            int rem=y%10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && rem > 7)) return 0;
            reverse*=10;
            reverse+=rem;
            y/=10;
         }

         if(reverse == x){
            return true;
         } else {
            return false;
         }
         
    }
};


int main(){
    Solution obj;
    int num;
    cout<<"Enter a Number : ";
    cin>>num;

    bool result=obj.isPalindrome(num);

    cout << "Result: " << result << std::endl;
}