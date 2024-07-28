class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        reverse(s.begin(),s.end());
        int n=stoi(s);
        if(s==x)
        return true;
        else return false;
    }
};