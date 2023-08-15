class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string prefix = strs[0];  // Initialize prefix with the first string

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j);  // Update prefix with the common part
            if (prefix.empty())
                break;  // If prefix becomes empty, no need to check further
        }

        return prefix;
    }
};
