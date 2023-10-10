class Solution {
    unordered_map<int,int> getFactors(int x){
        unordered_map<int,int> freq;
        int f=2;
        while(x>1 && f*f<=x){
            while(x%f==0){
                freq[f]++;
                x/=f;
            }
            f++;
        }
        if(x!=1)    freq[x]=1;       
        return freq;
    }
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
        {
            auto y=getFactors(x);
            for(auto &[i,j]:y)
              m[i] +=j;
        }
        int n=nums.size();
        unordered_map<int,int>m1;
        int k=0;
        for(auto x:nums){
            auto y=getFactors(x);
            for(auto &[i,j]:y){
               m1[i] +=j;
               m[i] -=j;
               if(m[i]==0)
                  m.erase(i);
            }
            bool a=true;
            for(auto x:m1){
                if(m.find(x.first)!=m.end()){
                    a=false;
                    break;
                }
            }
            if(k==n-1)
              return -1;
            if(a)
             return k;
            k++;
        }
        return -1;
    }
};