class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int, int>mp;
        for(auto x :arr1){
            mp[x]++;
        }
            for(auto y :arr2){
                if(mp.find(y)!=mp.end()){
                    auto x = mp.find(y);
                    int count = x->second;
                    vector<int>v(count ,y);
                    ans.insert(ans.end() , v.begin(), v.end() );
                    mp.erase(y);
                }
            }
            for(auto x:mp){
                int ele =x.first;
                int count = x.second;
                vector<int>v(count ,ele);
                ans.insert(ans.end() , v.begin(), v.end() );


            }

        
        return ans;

        
    }
};