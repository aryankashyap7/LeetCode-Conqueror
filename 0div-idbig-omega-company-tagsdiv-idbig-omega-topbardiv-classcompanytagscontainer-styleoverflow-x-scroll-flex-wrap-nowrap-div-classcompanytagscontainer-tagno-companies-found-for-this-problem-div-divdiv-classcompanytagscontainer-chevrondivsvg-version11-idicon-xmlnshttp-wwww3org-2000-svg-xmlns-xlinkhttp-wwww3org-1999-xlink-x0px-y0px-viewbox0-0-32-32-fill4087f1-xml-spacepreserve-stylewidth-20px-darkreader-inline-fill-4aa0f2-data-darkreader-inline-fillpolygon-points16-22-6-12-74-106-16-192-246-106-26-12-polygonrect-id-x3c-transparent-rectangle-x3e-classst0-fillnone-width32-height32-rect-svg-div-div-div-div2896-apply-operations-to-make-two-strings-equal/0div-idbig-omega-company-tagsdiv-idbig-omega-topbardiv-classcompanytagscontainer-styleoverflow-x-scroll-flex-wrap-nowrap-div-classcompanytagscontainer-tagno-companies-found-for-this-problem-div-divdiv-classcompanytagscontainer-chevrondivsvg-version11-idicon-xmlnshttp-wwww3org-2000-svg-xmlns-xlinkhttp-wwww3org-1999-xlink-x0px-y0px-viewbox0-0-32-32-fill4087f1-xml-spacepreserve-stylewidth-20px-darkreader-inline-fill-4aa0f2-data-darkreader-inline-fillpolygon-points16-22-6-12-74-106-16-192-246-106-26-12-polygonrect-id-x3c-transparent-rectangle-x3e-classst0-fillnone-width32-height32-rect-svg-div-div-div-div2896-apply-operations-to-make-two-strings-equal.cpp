class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int last_diff_idx = -1, dp_pp = -1, dp_p = 0;
        int count_diff = 0;

        for( int i = 0 ; i < s1.size() ; i++ ) {
            if( s1[i] == s2[i] )
                continue;

            count_diff++;

            int dp = dp_p + x;
            if( last_diff_idx != -1 )
                dp = min(dp, dp_pp + 2*(i - last_diff_idx));

            last_diff_idx = i;
            dp_pp = dp_p, dp_p = dp;
        }

        if( count_diff % 2 != 0 )
            return -1;
            
        return dp_p / 2;
    }
};