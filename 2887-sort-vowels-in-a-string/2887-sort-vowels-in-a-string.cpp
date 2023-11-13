class Solution {
public:
    
    string sortVowels(string s) {
        vector<int> index;
        vector<char> chars;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                index.push_back(i);
                chars.push_back(s[i]);
            }
        }

        sort(chars.begin(), chars.end());
        
        for(int i = 0; i<index.size(); i++){
            s[index[i]] = chars[i];
        }
        return s;
    }
};