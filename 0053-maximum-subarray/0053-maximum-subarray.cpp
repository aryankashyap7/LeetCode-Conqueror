class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadanes implementation
        int maxTillNow=nums[0];
        int maxSoFar=nums[0];

        for(int i=1;i<nums.size();i++){
            maxTillNow=max(nums[i],maxTillNow+nums[i]);
            maxSoFar=max(maxSoFar,maxTillNow);
        }
        return maxSoFar;
    }
};