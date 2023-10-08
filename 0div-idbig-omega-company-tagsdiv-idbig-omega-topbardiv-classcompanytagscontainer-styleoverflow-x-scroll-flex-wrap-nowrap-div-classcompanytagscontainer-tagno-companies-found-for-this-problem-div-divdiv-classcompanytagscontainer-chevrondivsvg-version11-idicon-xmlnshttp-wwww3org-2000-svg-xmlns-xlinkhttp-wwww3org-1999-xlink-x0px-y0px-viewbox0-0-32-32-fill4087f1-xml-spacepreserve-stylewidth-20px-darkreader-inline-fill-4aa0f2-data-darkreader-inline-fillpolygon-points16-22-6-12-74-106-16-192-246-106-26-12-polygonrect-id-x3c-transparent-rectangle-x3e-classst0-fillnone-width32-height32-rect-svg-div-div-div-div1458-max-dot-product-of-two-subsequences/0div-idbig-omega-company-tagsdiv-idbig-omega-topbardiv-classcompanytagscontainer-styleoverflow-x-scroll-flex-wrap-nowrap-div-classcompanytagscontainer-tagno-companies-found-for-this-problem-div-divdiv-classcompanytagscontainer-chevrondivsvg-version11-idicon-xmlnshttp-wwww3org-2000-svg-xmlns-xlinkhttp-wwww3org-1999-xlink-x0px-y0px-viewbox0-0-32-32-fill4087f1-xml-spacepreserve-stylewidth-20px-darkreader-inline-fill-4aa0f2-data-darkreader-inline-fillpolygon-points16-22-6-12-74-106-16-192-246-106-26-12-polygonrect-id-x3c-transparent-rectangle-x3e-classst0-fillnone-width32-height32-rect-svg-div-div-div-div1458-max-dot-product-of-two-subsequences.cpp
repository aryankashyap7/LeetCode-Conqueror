class Solution {
private:
    const int INF=1e9;
    vector<vector<int>> dp;
    int helper(int i,int j,vector<int> &nums1,vector<int> &nums2) {
        //base cases
        if(i<0 or j<0) return -INF;
        if(dp[i][j]!=-1) return dp[i][j];

        int take=max(nums1[i]*nums2[j],nums1[i]*nums2[j]+helper(i-1,j-1,nums1,nums2));
        int notTake=max(helper(i-1,j,nums1,nums2),helper(i,j-1,nums1,nums2));
        return dp[i][j]=max(take,notTake);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(nums1.size()-1,nums2.size()-1,nums1,nums2);
    }
};