class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first element from the right that is smaller than its adjacent element
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            // Step 2: Find the smallest element to the right of nums[i] but greater than nums[i]
            int j = n - 1;
            while (j > i && nums[j] <= nums[i])
                j--;

            // Step 3: Swap the elements and sort the remaining elements
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        } else {
            // If no such element is found, reverse the entire vector
            reverse(nums.begin(), nums.end());
        }

        // Print the next permutation
        for (auto x : nums)
            cout << x << " ";
    }
};
