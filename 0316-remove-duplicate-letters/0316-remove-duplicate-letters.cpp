class Solution {
public:
    string removeDuplicateLetters(const string& s) {
        map<int, int> charFrequency;    // To keep track of character frequencies
        vector<int> visited(26, 0);     // To mark characters as visited
        stack<char> charStack;          // Stack to build the result

        // Count the frequency of each character in the string
        for (char c : s) {
            charFrequency[c - 'a']++;
        }

        // Iterate through each character in the string
        for (char c : s) {
            charFrequency[c - 'a']--;   // Decrease the character frequency

            if (visited[c - 'a']) {
                continue;               // Skip characters that are already visited
            }

            // Maintain the lexicographically smallest result
            while (!charStack.empty() && charStack.top() > c && charFrequency[charStack.top() - 'a'] > 0) {
                visited[charStack.top() - 'a'] = 0;   // Mark previous characters as not visited
                charStack.pop();                      // Remove characters that can be replaced
            }

            charStack.push(c);         // Add the current character to the stack
            visited[c - 'a'] = 1;      // Mark the character as visited
        }

        string ans;
        // Construct the result by popping characters from the stack
        while (!charStack.empty()) {
            ans += charStack.top();
            charStack.pop();
        }

        reverse(ans.begin(), ans.end());    // Reverse the result to get the correct order
        return ans;
    }
};