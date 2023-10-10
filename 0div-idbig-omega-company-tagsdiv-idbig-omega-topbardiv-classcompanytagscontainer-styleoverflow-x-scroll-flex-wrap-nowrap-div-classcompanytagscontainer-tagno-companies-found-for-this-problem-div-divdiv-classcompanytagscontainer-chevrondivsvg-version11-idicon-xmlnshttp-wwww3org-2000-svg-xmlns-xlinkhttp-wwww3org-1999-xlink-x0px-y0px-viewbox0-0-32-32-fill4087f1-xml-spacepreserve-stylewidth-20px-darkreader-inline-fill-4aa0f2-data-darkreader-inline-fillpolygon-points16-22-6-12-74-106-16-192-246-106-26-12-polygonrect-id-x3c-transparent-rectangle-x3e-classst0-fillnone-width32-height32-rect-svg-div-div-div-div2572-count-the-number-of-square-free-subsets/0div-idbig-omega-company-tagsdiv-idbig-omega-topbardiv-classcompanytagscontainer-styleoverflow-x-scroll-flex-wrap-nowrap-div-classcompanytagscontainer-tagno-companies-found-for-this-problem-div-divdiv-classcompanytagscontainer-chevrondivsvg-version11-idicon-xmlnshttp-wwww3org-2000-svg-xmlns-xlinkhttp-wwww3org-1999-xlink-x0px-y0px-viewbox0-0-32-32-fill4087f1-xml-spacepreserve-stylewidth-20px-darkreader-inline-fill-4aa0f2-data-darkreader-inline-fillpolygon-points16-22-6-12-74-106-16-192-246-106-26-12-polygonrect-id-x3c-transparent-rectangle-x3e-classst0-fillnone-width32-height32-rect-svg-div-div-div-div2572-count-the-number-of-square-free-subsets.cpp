class Solution {
    long long MOD = 1e9 + 7;
public:
    bool check_already_set_bits(int a, int b)
    {
        for(int i = 0; i < 11; ++i)
        {
            int temp = (1 << i);
            if((a & temp) && (b & temp)) return false;
        }
        return true;
    }
    int helper(vector<int>& nums, int index, vector<int> &bm, int res, vector<vector<int>> &dp)
    {
        
        if(index == nums.size())
        {
            return 1;
        }
        if(dp[index][res] != -1) return dp[index][res];

        int include{};
        if(bm[index] != -1 && check_already_set_bits(res, bm[index])) //condition to include => check if the prime factor is not already present in result
        {       
            include =  helper(nums, index+1, bm, res | bm[index], dp);
        }
        int exclude = helper(nums, index + 1, bm, res, dp);

        return dp[index][res] = (include + exclude) % MOD;
    }

    int squareFreeSubsets(vector<int>& nums) {

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> bm{};
        for(int i: nums)
        {
            int k{};
            int bitmask = 0;
            while(i != 1)
            {
                while(i%primes[k] == 0)
                {
                    i /= primes[k];
                    if(bitmask & (1 << k))  //if already set bit or prime number is already found
                    {
                        bitmask = -1;
                        break;
                    }
                    else
                    {
                        bitmask |= (1 << k);
                    }
                }
                if(bitmask == -1)
                {
                    bm.push_back(bitmask);
                    break;
                }
                k++;
            }
            if(bitmask != -1)
                bm.push_back(bitmask);
        }

     
        vector<vector<int>> dp(nums.size(), vector<int>(1 << 11, -1));
        int  res{};
        int ans = helper(nums, 0, bm, res, dp) - 1;
        return ans != -1 ? ans: 1e9+6;
        
    }
};