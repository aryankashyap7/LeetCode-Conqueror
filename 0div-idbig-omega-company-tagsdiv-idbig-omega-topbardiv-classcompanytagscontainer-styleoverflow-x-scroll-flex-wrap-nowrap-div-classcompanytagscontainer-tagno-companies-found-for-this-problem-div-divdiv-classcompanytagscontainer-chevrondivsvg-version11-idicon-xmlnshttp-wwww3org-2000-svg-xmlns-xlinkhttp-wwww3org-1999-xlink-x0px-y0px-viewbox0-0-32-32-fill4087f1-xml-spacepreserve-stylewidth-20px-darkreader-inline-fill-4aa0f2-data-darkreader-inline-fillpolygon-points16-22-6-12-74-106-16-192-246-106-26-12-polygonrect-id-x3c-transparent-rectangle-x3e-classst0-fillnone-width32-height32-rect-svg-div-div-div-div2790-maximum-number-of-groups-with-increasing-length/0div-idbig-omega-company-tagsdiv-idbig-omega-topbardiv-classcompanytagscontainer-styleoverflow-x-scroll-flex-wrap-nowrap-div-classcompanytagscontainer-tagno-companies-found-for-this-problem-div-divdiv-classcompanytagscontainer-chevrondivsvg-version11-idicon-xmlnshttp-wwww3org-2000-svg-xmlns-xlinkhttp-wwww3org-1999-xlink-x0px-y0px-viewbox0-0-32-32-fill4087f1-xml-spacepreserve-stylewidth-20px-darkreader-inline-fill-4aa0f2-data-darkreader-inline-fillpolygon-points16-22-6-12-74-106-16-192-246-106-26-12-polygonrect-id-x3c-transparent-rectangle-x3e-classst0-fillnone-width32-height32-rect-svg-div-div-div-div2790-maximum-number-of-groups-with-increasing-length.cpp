class Solution {
public:
    int maxIncreasingGroups(vector<int>& u) {
        int l=0;
        sort(u.begin(),u.end());
        int n = u.size();
        long long mp=0;
        for(int i=0;i<n;i++){
           if(u[i]>l){
               l++;
               u[i]=u[i]-(l);
               mp= (mp+(long long)u[i]);
           }
           else if(u[i]<=l){
               if(u[i]+mp>l){
                   l++;
                   long long x = (long long)l-(long long)u[i];
                   mp = mp-x;
                  
               }
               else{
                   mp+=(long long)u[i];
               }
                
           }
          
        }
        return l;
    }
};