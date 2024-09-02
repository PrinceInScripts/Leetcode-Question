int sum=0;
        for(auto el:chalk) sum+=el;
        while(sum<=k) k-=sum;
        int ans;
        for(int i=0;i<chalk.size();i++){
            if(k<chalk[i]){
                ans=i;
                break;
            } else k-=chalk[i];
        }