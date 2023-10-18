class Solution {
public:vector<int> time;
    int t(int i,vector<vector<int>> &a,vector<int> &dp)
    {
        if(dp[i]!=-1) return dp[i];

        int s=0;
        for(auto j : a[i])
                s=max(s,t(j,a,dp));

        return dp[i]=s+time[i-1];
    }
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& tt) {
        vector<int> dp(n+2,-1),l(n+2,0);
        vector<vector<int>> a(n+2);
        time=tt;
        for(auto i : r)
            {
                l[i[0]]++;
                a[i[1]].push_back(i[0]);}
        
        int m=0;
        for(int i=1;i<=n;i++)
        {
            if(l[i]==0) 
            m=max(m,t(i,a,dp));}
        
        return m;
    }
};