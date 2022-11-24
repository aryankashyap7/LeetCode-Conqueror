class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, 0);

        int count0 = count(nums.begin(), nums.end(), 0);
        if (count0 < 1)
        {
            int prod = 1;
            for (int i = 0; i < n; i++)
                prod *= nums[i];
            for (int i = 0; i < n; i++)
                ans[i] = prod / nums[i];
        }
        else if (count0 == 1)
        {
            int prod = 1;
            int index;
            for (int i = 0; i < n; i++)
                if (nums[i] != 0)
                    prod *= nums[i];
                else
                    index = i;

            ans[index] = prod;
        }
        return ans;
    }
};