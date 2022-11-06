class Solution {
public:
    int firstMissingPositive(vector<int> &nums)
{

    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    int res = 1;
    while (m[res] != 0)
        res++;
    return res;
}
};