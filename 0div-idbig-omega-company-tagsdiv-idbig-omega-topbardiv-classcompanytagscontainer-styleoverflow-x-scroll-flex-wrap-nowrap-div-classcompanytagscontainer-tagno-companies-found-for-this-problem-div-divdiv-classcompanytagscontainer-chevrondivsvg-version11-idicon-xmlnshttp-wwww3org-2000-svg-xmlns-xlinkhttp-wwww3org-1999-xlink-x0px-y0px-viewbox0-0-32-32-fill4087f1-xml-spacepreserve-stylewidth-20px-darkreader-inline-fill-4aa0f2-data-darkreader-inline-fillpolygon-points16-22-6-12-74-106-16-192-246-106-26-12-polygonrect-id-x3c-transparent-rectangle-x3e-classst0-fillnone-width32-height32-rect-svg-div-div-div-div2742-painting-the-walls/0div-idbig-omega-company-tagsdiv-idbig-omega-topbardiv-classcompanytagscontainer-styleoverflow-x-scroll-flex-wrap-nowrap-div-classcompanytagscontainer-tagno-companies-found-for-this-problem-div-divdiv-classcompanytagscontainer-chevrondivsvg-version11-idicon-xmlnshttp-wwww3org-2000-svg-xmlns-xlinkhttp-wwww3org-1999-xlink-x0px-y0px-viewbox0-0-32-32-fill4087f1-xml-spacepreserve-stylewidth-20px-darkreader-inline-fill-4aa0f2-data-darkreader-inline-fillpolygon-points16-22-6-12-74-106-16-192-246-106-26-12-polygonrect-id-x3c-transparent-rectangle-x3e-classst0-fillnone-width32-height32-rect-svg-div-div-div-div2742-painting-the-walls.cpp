class Solution {
    private:
    int solve(int i, int ti, int n, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if(ti>=n) return 0;
        if(i>=n) return 1e9+1;
        //if(i==n-1 and ti+time[n-1]+1>=n) 
        
        if(dp[i][ti]!=-1) return dp[i][ti];

        int take=cost[i]+solve(i+1, ti + time[i]+1, n, cost, time, dp);
        int notTake=solve(i+1, ti, n, cost, time, dp);

        return dp[i][ti] = min(take, notTake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=time[i];
        vector<vector<int>> dp(n, vector<int> (sum+n+1, -1));
        return solve(0, 0, n, cost, time, dp);
    }
};