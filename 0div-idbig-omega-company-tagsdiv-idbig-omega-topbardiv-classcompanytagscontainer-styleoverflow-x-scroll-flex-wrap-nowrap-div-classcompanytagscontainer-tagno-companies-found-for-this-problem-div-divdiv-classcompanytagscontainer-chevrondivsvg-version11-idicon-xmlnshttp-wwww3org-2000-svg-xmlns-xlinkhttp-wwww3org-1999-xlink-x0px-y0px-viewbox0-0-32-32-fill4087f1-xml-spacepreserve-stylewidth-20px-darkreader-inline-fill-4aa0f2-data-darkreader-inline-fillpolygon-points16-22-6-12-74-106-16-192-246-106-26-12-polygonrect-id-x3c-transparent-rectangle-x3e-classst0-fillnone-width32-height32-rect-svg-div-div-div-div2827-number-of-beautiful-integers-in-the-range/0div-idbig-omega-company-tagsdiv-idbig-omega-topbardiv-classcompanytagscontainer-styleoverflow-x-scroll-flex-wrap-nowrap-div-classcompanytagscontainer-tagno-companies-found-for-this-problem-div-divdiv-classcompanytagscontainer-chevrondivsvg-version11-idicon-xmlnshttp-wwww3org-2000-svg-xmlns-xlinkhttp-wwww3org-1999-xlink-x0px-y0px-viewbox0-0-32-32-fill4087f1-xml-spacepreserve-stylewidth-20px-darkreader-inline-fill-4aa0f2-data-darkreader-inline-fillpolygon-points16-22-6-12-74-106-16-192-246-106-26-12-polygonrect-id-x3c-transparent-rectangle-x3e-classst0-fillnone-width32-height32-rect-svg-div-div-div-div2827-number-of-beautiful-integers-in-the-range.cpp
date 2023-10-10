class Solution {
public:
    int d;
    string s;
    int dp[11][2][11][11][21]; 

    int solve(int idx, int flg, int ev, int od, int rem, int z){

        if(idx == s.size()){
            if(ev == od && rem == 0) return 1;
            else return 0;
        }

        if(dp[idx][flg][ev][od][rem] != -1) return dp[idx][flg][ev][od][rem];

        int n = flg ? s[idx] - '0': 9;
        int cnt = 0;
        for(int i=0; i<=n; i++){
            int rem1 = (rem*10 + i)%d;
            int flg1 = flg & (n == i);
            int z1 = z & (i == 0);
            if(i%2 == 0) cnt += solve(idx+1, flg1, (z1 ? ev : ev+1), od, rem1, z1);
            else cnt += solve(idx+1, flg1, ev, od+1, rem1, z1);
        } 
        return dp[idx][flg][ev][od][rem] = cnt;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        d = k;

        memset(dp, -1, sizeof(dp)); 
        s = to_string(low-1);
        int l = solve(0, 1, 0, 0, 0, 1);
        
        memset(dp, -1, sizeof(dp));   
        s = to_string(high);
        int r = solve(0, 1, 0, 0, 0, 1);

        return r-l;
    }
};