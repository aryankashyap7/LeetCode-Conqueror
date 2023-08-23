class Solution {
public:
    string reorganizeString(string s) {
        string result = ""; 
        unordered_map<char, int> charFreq;
        
        for(char c : s){
            charFreq[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto entry : charFreq){
            pq.push({entry.second, entry.first});
        }

        while(!pq.empty()){
            pair<int, char> mostFreq = pq.top();
            pq.pop();

            if(result.empty() || result.back() != mostFreq.second){
                result.push_back(mostFreq.second);
                if(--mostFreq.first > 0){
                    pq.push(mostFreq);
                }
            }
            else{
                if(pq.empty()) return "";
                pair<int, char> nextFreq = pq.top();
                pq.pop();
                result.push_back(nextFreq.second);
                if(--nextFreq.first > 0){
                    pq.push(nextFreq);
                }
                pq.push(mostFreq);
            }
        }

        return result;
    }
};
