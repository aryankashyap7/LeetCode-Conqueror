class Solution {
public:
    int mySqrt(long long int x)
{

    long long int l = 0, r = x;
    long long int ans = 0;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
};