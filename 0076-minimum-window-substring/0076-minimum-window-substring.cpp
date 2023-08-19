class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetCount; // Stores character frequencies in 't'
        unordered_map<char, int> windowCount; // Stores character frequencies in the current window

        // Count the characters in 't'
        for (char c : t) {
            targetCount[c]++;
        }

        int left = 0; // Left pointer of the sliding window
        int minLen = INT_MAX; // Minimum window length found
        int minStart = 0; // Start index of the minimum window
        int count = 0; // Count of characters in 't' found in 's'

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            // Update windowCount
            windowCount[c]++;

            // Check if we have found all required characters in 's'
            if (targetCount.find(c) != targetCount.end() && windowCount[c] <= targetCount[c]) {
                count++;
            }

            // If all characters in 't' are found, try to minimize the window
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];

                windowCount[leftChar]--;
                if (targetCount.find(leftChar) != targetCount.end() && windowCount[leftChar] < targetCount[leftChar]) {
                    count--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLen);
    }
};