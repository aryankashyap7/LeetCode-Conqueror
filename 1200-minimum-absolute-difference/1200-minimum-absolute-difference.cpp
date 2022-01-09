class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minval = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++)
            minval = min(minval, arr[i]-arr[i-1]);

            
        vector<vector<int>> mindiff;
        for(int j = 1; j < arr.size();j++)
        {
            if(arr[j]-arr[j-1] == minval)
            {
                mindiff.push_back({arr[j-1], arr[j]});
            }
        }
        
    return mindiff;
    }
};