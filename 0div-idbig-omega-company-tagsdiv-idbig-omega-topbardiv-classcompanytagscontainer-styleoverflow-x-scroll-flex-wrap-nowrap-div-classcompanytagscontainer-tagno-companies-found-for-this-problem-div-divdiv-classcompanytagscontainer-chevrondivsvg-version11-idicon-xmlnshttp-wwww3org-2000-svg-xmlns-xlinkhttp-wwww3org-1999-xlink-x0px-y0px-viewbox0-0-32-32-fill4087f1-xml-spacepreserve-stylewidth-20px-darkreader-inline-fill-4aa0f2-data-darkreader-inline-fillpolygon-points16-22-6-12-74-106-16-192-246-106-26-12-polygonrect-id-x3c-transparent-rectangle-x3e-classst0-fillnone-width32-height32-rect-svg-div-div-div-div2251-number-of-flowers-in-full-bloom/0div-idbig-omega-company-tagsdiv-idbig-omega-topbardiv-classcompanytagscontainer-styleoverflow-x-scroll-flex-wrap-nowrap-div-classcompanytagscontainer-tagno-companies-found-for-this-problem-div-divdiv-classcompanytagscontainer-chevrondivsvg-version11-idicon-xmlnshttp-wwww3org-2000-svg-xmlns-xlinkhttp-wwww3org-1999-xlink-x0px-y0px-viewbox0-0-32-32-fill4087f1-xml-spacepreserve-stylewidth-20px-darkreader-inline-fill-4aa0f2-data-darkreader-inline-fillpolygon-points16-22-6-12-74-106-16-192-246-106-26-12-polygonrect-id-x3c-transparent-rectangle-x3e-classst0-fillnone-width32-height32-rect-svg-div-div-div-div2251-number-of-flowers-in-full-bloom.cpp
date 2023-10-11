class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> starts, ends;
        for(auto time: flowers)
        {
            starts.push_back(time[0]);
            ends.push_back(time[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans;
        for(auto curr_time: people)
        {
            int ub = upper_bound(starts.begin(), starts.end(), curr_time) - starts.begin();
            int lb = lower_bound(ends.begin(), ends.end(), curr_time) - ends.begin();
            ans.push_back(ub - lb);
        }
        return ans;
    }
};