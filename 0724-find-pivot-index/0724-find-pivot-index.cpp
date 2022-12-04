class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {

        int tsum = 0, psum = 0, index = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            tsum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {

            if (psum == tsum - nums[i] - psum)
            {
                index = i;
                // cout << "Break at:" << psum << " " << tsum - nums[i] - psum << "\n";

                break;
            }

            // cout << psum << " " << tsum - nums[i] << "\n";
            psum += nums[i];
        }

        return index;
    }
};