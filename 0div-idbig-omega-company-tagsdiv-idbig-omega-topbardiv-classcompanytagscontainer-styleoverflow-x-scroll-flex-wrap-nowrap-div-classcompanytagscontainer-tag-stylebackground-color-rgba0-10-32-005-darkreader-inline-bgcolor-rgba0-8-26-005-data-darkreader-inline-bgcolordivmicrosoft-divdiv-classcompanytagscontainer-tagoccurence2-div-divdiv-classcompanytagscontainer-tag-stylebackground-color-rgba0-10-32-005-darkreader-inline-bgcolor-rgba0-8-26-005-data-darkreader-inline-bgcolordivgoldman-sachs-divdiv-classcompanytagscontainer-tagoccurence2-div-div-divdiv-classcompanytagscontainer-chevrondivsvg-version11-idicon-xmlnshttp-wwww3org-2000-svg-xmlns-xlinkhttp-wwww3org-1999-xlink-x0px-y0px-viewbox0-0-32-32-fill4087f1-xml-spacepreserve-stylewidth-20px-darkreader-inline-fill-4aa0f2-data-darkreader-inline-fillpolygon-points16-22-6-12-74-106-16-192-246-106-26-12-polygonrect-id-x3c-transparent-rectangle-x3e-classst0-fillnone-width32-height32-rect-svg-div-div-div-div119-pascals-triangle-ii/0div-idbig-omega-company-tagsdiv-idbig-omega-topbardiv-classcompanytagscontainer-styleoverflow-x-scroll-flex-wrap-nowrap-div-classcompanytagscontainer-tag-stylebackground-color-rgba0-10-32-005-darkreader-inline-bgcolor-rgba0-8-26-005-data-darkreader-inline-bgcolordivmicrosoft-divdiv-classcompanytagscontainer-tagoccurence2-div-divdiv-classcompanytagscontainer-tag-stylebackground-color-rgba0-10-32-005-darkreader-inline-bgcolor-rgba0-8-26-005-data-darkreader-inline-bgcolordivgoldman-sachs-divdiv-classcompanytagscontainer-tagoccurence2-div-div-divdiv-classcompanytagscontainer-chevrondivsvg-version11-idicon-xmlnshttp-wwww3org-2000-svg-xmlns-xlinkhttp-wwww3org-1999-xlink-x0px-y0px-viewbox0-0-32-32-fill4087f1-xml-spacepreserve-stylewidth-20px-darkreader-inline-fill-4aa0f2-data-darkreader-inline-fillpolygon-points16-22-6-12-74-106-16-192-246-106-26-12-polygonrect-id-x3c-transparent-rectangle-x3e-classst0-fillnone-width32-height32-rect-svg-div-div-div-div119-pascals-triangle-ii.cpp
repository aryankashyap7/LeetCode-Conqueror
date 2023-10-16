class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v;
        for(int i=0; i<=rowIndex; i++){
            vector<int>ans(i+1, 1);
            for(int j=1; j< i; j++){
                 ans[j] = v[i-1][j] + v[i-1][j-1];
            }
            v.push_back(ans);
        }
        return v[rowIndex];
 
    }
};