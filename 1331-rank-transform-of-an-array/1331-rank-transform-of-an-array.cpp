class Solution
{

public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {

        map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        int rank = 1;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            it->second = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            v.push_back(mp[arr[i]]);
        }
        return v;
    }
};