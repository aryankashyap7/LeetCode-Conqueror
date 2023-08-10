class Solution {
public:
    int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            // The right half is still sorted, the minimum is in the left half
            right = mid;
        } else {
            // The left half is still sorted, the minimum is in the right half
            left = mid + 1;
        }
    }

    return nums[left];
}

};