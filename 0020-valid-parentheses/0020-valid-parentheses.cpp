class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        
        for (auto x : s) {
            if (x == '(' || x == '{' || x == '[')
                k.push(x);
            else if (!k.empty() && x == ')' && k.top() == '(')
                k.pop();
            else if (!k.empty() && x == '}' && k.top() == '{')
                k.pop();
            else if (!k.empty() && x == ']' && k.top() == '[')
                k.pop();
            else
                return false;
        }
        
        return k.empty();
    }
};
