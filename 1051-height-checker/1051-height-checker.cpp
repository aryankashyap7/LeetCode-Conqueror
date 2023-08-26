class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> sh(heights);
        sort(sh.begin(),sh.end());
        
        int c=0;
        for(int i=0;i<sh.size();i++){
            if(sh[i]!=heights[i])c++;
        }
        
        return c;
    }
};