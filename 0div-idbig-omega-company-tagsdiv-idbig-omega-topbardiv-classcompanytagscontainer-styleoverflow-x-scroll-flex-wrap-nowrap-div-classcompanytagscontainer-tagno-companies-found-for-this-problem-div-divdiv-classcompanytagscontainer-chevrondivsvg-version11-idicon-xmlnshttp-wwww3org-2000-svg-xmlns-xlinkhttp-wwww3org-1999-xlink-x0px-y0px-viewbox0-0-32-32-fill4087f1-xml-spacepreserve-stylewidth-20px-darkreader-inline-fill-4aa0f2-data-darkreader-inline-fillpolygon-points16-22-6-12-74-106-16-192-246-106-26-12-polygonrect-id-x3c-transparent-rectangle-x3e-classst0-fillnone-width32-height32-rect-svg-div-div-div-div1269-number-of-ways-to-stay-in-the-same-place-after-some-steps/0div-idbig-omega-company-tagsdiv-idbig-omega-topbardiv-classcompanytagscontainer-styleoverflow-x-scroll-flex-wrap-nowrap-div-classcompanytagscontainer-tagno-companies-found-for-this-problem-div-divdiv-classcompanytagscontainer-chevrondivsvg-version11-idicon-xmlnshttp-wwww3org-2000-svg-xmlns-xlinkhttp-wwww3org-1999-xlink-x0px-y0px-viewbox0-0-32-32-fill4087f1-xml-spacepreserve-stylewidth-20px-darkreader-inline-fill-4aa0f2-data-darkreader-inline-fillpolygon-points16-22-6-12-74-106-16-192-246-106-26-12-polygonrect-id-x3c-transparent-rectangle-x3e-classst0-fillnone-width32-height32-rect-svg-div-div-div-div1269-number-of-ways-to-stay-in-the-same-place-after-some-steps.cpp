class Solution {
public:
    int dp[501][501];
    int mod=1000000007;
    int solve(int steps,int arrLen,int l)
    {
        if(steps==0)
        {
            if(l==0)
            {
                return 1;
            }
            return 0;
        }

        if(l<0 || l>=arrLen)
        {
            return 0;
        }

        if(dp[steps][l]!=-1)
        {
            return dp[steps][l];
        }

        int left=solve(steps-1,arrLen,l-1)%mod;
        int right=(solve(steps-1,arrLen,l+1)+solve(steps-1,arrLen,l))%mod;

        return dp[steps][l]=(left+right)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(steps,arrLen,0);
    }
};