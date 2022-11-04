class Solution {
public:
    string reverseVowels(string s)
{
    vector<char> vow;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vow.push_back(c);

    int cnt = 0;
    reverse(vow.begin(), vow.end());
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            s[i] = vow[cnt++];
    return s;
}
};