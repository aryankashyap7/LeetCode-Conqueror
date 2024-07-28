class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        bool neg = false;

        if (s[0] == '-') {
            neg = true;
            s = s.substr(1);
        }

        string reversedStr = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            reversedStr += s[i];
        }

        try {
            int reversedInt = stoi(reversedStr);
            return neg ? -reversedInt : reversedInt;}
        catch(out_of_range &e){
            return 0;
        }
    }
};
