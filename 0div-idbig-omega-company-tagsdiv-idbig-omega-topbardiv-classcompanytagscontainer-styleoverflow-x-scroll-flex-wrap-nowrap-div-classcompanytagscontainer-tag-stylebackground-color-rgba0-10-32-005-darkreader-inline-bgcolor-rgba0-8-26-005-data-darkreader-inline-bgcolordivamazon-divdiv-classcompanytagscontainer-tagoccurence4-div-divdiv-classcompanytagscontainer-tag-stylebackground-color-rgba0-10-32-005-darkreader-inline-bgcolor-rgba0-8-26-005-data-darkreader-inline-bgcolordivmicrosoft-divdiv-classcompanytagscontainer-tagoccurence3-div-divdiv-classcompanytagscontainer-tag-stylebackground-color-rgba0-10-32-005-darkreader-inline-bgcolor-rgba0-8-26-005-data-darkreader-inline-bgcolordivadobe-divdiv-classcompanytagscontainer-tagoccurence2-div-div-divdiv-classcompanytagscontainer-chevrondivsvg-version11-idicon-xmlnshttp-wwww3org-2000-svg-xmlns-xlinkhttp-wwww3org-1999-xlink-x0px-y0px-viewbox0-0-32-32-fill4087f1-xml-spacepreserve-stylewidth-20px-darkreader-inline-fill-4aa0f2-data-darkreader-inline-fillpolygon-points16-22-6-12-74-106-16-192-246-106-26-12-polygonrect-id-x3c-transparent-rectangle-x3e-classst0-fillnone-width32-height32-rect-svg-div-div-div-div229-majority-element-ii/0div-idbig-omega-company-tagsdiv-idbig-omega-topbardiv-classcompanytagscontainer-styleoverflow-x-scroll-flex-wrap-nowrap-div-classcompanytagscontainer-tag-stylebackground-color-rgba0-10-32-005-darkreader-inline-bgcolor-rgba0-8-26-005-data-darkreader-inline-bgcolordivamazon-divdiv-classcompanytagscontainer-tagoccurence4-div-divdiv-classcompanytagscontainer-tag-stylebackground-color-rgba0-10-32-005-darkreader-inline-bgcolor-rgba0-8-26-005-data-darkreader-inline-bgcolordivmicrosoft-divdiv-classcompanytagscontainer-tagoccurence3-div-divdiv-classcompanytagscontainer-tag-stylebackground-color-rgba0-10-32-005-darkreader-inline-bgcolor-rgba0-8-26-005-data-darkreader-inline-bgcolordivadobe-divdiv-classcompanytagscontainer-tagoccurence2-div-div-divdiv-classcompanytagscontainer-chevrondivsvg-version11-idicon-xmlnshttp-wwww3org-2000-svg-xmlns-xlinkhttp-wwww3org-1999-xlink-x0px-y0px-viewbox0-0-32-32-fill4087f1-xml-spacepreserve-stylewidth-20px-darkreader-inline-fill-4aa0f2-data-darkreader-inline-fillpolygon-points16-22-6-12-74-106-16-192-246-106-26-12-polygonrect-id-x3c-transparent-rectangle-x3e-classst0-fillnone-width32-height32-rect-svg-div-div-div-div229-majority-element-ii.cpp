class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        map<int,int>::iterator ir=m.begin();
        for(;ir!=m.end();ir++)
        {
            if(ir->second>nums.size()/3)
                v.push_back(ir->first);
        }
        return v;
        
    }
};