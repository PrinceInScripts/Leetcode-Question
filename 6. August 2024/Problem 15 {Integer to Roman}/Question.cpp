

/*
# 12. Integer to Roman
*/
/*
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999
 
*/


#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<set>
#include<regex>
#include<string>
using namespace std;

class Solution {
public:  
    string intToRoman1(int num) {
        unordered_map<int,string> intRomView={
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        };

        string ans="";
       while(num!=0){
        if(num>=1000){
          while(num>=1000){
           num-=1000;
           ans+=intRomView[1000];
          }
        } 
        else if(num>=900){
            num-=900;
            ans+=intRomView[900];
        }
        else if(num>=500){
            num-=500;
            ans+=intRomView[500];
        }
        else if(num>=400){
            num-=400;
            ans+=intRomView[400];
        }
        else if(num>=100){
            num-=100;
            ans+=intRomView[100];
        }
        else if(num>=90){
            num-=90;
            ans+=intRomView[90];
        }
        else if(num>=50){
            num-=50;
            ans+=intRomView[50];
        }
        else if(num>=40){
            num-=40;
            ans+=intRomView[40];
        }
        else if(num>=10){
            num-=10;
            ans+=intRomView[10];
        }
        else if(num>=9){
            num-=9;
            ans+=intRomView[9];
        }
        else if(num>=5){
            num-=5;
            ans+=intRomView[5];
        }
        else if(num>=4){
            num-=4;
            ans+=intRomView[4];
        }
        else if(num>=1){
            num-=1;
            ans+=intRomView[1];
        }
       }

        return ans;

    }
    string intToRoman(int num) {
       

       vector<int> integer={1000,900,500,400,100,90,50,40,10,9,5,4,1};
       vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

       string str="";
       int i=0;
       while(num>0){
          if(num>=integer[i]){
             str+=roman[i];
             num-=integer[i];
          } else {
            i++;
          }
       }
       return str;

    }
    
    
        
};


int main(){
  int num=1994;
   Solution solution; 
 string ans= solution.intToRoman(num);

  cout<<ans<<endl;
  return 0;

}
