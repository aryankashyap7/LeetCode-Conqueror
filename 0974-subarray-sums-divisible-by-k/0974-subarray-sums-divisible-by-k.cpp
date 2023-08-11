class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int K) {
          int n = nums.size();
    unordered_map<int, int> freqMap;
    freqMap[0] = 1;  // Initial frequency to handle subarrays starting from index 0
    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum = (prefixSum + num) % K;
        if (prefixSum < 0) {
            prefixSum += K;  // Ensure non-negative prefix sums
        }
        count += freqMap[prefixSum];
        ++freqMap[prefixSum];
    }

    return count;
    }
};