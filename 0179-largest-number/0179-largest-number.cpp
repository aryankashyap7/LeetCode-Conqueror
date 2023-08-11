class Solution {
public:
    static bool compareNums(const string &a, const string &b) {
        return a + b > b + a; // Compare concatenated strings
    }
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numStrs(n);
        
        for (int i = 0; i < n; ++i) {
            numStrs[i] = to_string(nums[i]);
        }
        
        sort(numStrs.begin(), numStrs.end(), compareNums);
        
        // Handle the case when the largest number is 0
        if (numStrs[0] == "0") {
            return "0";
        }
        
        string ans;
        for (const string &numStr : numStrs) {
            ans += numStr;
        }
        
        return ans;
    }
};
