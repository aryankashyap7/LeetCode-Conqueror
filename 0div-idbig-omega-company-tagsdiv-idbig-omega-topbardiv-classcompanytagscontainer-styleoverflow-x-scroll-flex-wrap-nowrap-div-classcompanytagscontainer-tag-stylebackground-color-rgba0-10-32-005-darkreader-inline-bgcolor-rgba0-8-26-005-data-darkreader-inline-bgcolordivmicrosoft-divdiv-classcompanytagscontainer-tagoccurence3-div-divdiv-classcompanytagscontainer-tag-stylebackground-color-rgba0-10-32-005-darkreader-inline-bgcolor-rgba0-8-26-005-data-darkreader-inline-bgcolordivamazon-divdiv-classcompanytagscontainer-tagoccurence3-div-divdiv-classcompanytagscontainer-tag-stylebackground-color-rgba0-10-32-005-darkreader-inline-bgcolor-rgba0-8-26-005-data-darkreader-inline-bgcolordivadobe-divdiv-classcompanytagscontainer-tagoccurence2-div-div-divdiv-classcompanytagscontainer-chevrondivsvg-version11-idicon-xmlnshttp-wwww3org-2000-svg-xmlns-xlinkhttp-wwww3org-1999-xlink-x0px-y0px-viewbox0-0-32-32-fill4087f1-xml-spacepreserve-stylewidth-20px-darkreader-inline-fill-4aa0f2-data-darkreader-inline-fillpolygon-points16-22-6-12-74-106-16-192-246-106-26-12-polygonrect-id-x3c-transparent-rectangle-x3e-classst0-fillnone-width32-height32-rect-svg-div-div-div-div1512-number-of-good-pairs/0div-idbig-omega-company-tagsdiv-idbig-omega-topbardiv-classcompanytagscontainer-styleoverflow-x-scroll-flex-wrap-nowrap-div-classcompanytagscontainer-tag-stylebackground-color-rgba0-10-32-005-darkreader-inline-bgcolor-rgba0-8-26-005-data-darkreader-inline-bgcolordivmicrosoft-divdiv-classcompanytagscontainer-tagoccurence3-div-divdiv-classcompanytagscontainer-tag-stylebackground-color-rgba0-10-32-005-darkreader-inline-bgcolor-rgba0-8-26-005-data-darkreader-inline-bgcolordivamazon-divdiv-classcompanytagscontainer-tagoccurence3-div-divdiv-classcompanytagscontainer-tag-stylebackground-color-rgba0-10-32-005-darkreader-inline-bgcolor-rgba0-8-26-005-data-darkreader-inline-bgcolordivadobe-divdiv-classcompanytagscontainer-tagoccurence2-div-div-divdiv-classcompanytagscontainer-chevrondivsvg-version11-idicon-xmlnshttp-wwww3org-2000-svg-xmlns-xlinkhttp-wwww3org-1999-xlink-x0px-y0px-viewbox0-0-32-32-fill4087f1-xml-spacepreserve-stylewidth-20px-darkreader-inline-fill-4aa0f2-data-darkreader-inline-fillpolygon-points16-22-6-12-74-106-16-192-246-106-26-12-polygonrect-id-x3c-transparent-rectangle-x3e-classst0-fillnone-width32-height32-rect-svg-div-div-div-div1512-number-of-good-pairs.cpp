class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        int count = 0;
        for (const auto& entry : freq) {
            count += (entry.second * (entry.second - 1)) / 2;
        }
        
        return count;
    }
};