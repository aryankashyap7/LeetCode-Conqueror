class Solution {
public:
string addBinary(string a, string b)
{

    if (a.length() < b.length())
        swap(a, b);

    int n = a.length();
    int m = b.length();
    int carry = 0;

    for (int i = n - 1, j = m - 1; i >= 0; i--, j--)
    {
        int sum = (a[i] - '0') + carry;
        if (j >= 0)
            sum += (b[j] - '0');
        a[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry)
        a = '1' + a;
    return a;
}
};