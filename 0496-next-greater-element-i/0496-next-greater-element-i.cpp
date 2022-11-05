class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        int j = 0;
        // find the index of nums1[i] in nums2
        while (nums2[j] != nums1[i])
            j++;
        // find the next greater element
        while (j < nums2.size() && nums2[j] <= nums1[i])
            j++;
        if (j == nums2.size())
            ans.push_back(-1);
        else
            ans.push_back(nums2[j]);
    }
    return ans;
}
};