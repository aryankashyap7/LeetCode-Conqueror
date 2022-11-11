class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> ans;
        for(int a:nums)
            ans.insert(a);
        int i=0;
        for(int s:ans)
        { nums[i]=s;i++;}
        
        
        return ans.size();
    }
};