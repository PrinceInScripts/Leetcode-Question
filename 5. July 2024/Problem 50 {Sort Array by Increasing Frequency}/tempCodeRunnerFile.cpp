 
          vector<pair<int,int>> numPairs;
         
          for(int i=0;i<nums.size();i++){
             vector<int> disNum=distributeNum(nums[i]);
             int s=0;
             for(int el:disNum){
               s=s*10+mapping[el];
             }
            numPairs.push_back({s,i});
          }
         
          stable_sort(numPairs.begin(),numPairs.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first<b.first;
          });
        

          vector<int> sortedNums;
          for(auto& el:numPairs){
            sortedNums.push_back(nums[el.second]);
          }

         return sortedNums;