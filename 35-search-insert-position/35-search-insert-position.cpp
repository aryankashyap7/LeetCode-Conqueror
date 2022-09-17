class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
{

    // Binary Search
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        // cout << "Start: " << start << " End: " << end << " Mid: " << mid << endl;
    }

    return (nums[mid] > target) ? mid : mid + 1;
}
};