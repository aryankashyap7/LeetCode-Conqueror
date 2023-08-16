class Solution {
public:
    vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements outside of the current window from the front
        while (!window.empty() && window.front() < i - k + 1) {
            window.pop_front();
        }

        // Remove smaller elements from the back as they won't affect the maximum
        while (!window.empty() && nums[i] >= nums[window.back()]) {
            window.pop_back();
        }

        // Add the current element to the back of the window
        window.push_back(i);

        // Add the maximum of the current window to the result
        if (i >= k - 1) {
            result.push_back(nums[window.front()]);
        }
    }

    return result;
}
};