class Solution {
public:
    int fact(int num){
        if(num<=1) return 1;
        else return (num * fact(num-1));
    }

    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> result;
        for(int i=0;i<=numRows-1;i++){
            vector<int> combi;
            for(int j=0;j<=i;j++){
                combi.push_back(fact(i)/(fact(i-j)*fact(j)));
            }
            result.push_back(combi);
        }
        
        return result;
    }
};