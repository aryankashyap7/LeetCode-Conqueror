class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 4)
            return n;
        int a = 2;
        int b = 3;
        int res = 0;
        for (int i = 4; i <= n; i++)
        {
            res = a + b;
            if (i % 2 == 0)
                a = res;
            else
                b = res;
        }
        return res;
    }
};