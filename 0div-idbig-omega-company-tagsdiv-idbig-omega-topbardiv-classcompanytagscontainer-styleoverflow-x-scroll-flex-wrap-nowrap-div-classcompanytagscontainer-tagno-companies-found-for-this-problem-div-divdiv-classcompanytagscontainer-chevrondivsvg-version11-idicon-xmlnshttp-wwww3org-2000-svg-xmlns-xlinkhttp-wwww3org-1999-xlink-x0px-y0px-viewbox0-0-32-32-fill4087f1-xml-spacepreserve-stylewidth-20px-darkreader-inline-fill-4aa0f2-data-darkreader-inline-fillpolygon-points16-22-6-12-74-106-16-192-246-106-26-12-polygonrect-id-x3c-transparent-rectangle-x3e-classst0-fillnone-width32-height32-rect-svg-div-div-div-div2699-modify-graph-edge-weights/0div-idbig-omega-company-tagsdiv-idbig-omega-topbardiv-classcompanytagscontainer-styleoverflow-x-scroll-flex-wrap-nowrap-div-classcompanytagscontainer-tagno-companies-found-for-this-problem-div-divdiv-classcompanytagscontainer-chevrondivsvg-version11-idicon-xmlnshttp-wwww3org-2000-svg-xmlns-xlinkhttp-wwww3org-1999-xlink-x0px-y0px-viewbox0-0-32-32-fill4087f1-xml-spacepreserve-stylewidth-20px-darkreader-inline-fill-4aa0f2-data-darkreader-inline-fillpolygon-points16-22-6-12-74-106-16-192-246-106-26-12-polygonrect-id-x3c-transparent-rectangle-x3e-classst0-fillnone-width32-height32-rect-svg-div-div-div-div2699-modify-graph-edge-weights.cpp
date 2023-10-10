class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int trgt) {
        vector<vector<pair<int,int>>> G(n);
        auto e = edges;
        vector<bool> is(e.size());
        for(int i = 0; i < e.size(); i++){
            G[e[i][0]].push_back({e[i][1], i}), G[e[i][1]].push_back({e[i][0], i});
            is[i] = e[i][2] == -1;
            if(is[i]) e[i][2] = 1;
        }
        auto Dijkstra = [&](vector<vector<pair<int,int>>> G, int src){
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
            vector<long long> dp(n, 1E9);
            q.push({0, src});
            dp[src] = 0;
            while(!q.empty()){
                auto [d, u] = q.top(); q.pop();
                for(auto [v, id] : G[u]){
                    if(dp[v] > dp[u] + e[id][2]){
                        dp[v] = dp[u] + e[id][2];
                        q.push({dp[v], v});
                    }
                }
            }
            return dp;
        };
        auto rev = Dijkstra(G, dest);
        auto check = [&](vector<vector<pair<int,int>>> G, int src){
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
            vector<long long> dp(n, 1E9);
            q.push({0, src});
            dp[src] = 0;
            while(!q.empty()){
                auto [d, u] = q.top(); q.pop();
                for(auto [v, id] : G[u]){
                    if(is[id] && dp[u] + 1 + rev[v] < trgt){
                        e[id][2] = max((long long)e[id][2], trgt - dp[u] - rev[v]);
                    }
                    if(dp[v] > dp[u] + e[id][2]){
                        dp[v] = dp[u] + e[id][2];
                        q.push({dp[v], v});
                    }
                }
            }
            if(dp[dest] == trgt) return true;
            return false;
        };
        if(check(G, src)) return e;
        return {};
    }
};