class DisjointSet {
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n) : rank(n, 0), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);
        if (node1 == node2)
            return;
        if (rank[node1] < rank[node2])
            swap(node1, node2);
        parent[node2] = node1;
        if (rank[node1] == rank[node2])
            rank[node1]++;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        DisjointSet obj(n);

        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int prime = 2; prime * prime <= x; prime++) {
                while (x % prime == 0) {
                    x /= prime;
                    if (m.find(prime) == m.end()) {
                        m[prime] = i;
                    } else {
                        obj.unionSet(m[prime], i);
                    }
                }
            }

            if (x > 1) {
                if (m.find(x) == m.end())
                    m[x] = i;
                else
                    obj.unionSet(m[x], i);
            }
        }

        int root = obj.findParent(0);
        for (int i = 0; i < n; i++) {
            if (obj.findParent(i) != root)
                return false;
        }
        return true;
    }
};
