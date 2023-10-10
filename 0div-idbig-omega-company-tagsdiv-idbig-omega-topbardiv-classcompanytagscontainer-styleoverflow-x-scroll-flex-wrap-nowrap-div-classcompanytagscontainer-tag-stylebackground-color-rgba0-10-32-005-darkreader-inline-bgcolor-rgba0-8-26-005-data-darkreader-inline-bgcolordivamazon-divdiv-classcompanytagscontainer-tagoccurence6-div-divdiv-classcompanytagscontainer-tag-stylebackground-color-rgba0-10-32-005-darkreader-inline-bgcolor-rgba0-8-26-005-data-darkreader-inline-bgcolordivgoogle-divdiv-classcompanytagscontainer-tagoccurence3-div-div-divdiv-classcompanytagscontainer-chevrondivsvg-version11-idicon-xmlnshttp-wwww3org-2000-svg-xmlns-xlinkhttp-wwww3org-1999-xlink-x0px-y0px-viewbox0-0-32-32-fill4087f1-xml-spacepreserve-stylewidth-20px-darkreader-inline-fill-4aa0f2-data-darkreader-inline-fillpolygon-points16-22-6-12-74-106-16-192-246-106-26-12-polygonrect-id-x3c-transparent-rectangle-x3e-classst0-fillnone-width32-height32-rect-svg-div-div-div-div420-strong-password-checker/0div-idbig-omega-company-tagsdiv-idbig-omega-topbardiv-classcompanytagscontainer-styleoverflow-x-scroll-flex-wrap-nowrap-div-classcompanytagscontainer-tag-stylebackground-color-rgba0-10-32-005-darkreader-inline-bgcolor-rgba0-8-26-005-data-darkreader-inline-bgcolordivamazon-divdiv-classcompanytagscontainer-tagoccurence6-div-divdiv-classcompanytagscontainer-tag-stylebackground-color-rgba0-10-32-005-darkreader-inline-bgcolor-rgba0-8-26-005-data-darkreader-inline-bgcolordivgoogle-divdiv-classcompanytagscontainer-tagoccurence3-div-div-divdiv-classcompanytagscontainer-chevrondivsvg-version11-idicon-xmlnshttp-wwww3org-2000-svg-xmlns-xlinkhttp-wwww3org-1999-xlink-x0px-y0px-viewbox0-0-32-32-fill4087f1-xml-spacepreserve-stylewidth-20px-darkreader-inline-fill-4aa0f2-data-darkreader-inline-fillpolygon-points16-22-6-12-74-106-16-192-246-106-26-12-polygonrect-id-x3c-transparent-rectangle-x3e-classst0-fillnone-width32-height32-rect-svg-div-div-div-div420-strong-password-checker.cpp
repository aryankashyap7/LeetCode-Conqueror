
class Solution {
public:
    int strongPasswordChecker(string password) {
        int length = password.size();
        int missingTypes = 3;

        // Check for missing character types
        if (any_of(password.begin(), password.end(), [](char c) { return islower(c); })) missingTypes--;
        if (any_of(password.begin(), password.end(), [](char c) { return isupper(c); })) missingTypes--;
        if (any_of(password.begin(), password.end(), [](char c) { return isdigit(c); })) missingTypes--;

        int requiredChanges = 0, consecutiveOneRepeat = 0, consecutiveTwoRepeats = 0;

        // Find repeating substrings
        for (int i = 2; i < length; i++) {
            if (password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                int repeatLength = 2;
                while (i < length && password[i] == password[i - 1]) {
                    repeatLength++;
                    i++;
                }
                requiredChanges += repeatLength / 3;
                if (repeatLength % 3 == 0) consecutiveOneRepeat++;
                if (repeatLength % 3 == 1) consecutiveTwoRepeats++;
                i--;
            }
        }

        // Determine the changes required
        if (length < 6) {
            return max(missingTypes, 6 - length);
        } else if (length <= 20) {
            return max(missingTypes, requiredChanges);
        } else {
            int deletions = length - 20;
            requiredChanges -= min(deletions, consecutiveOneRepeat * 1) / 1;
            requiredChanges -= min(max(deletions - consecutiveOneRepeat, 0), consecutiveTwoRepeats * 2) / 2;
            requiredChanges -= min(max(deletions - consecutiveOneRepeat - 2 * consecutiveTwoRepeats, 0), requiredChanges * 3) / 3;
            return deletions + max(missingTypes, requiredChanges);
        }
    }
};