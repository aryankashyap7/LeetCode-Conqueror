class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool val=false;
        for (int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                val=true;break;
            }
        }
    return val;
    }
};