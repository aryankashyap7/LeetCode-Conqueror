class Solution {
public:
    const long long MOD = 1e9+7;
    vector<vector<vector<int>>>dp;

    int ways(int n, int maxVal, int cost){
        if (cost < 1 || maxVal < 1){
            return 0;
        }
        if (n == 1){
            return (cost == 1);
        }
        if (dp[n][maxVal][cost] != -1){
            return dp[n][maxVal][cost];
        }
        long long w = ((long long)maxVal * ways(n - 1, maxVal, cost)) % MOD;
        for(int i = 1; i < maxVal; i++){
            w = (w + ways(n - 1, i, cost - 1)) % MOD;
        }
        return (dp[n][maxVal][cost] = w % MOD);
    }

    int numOfArrays(int n, int m, int k){
        dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        long long int res = 0;
        for(int i = 1; i <= m; i++){
            res = (res + ways(n, i, k)) % MOD;
        }
        return res;
    }
};