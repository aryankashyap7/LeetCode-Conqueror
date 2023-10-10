class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> out(n, -1);

        for (int node : banned) {
            out[node] = -2;
        }

        vector<int> nodes{p};
        int depth = 0;
        out[p] = depth;
        int step = k - 1;

        vector<int> nextNode2s(n, 0);
        for (int i = 0; i < n; ++i) {
            nextNode2s[i] = i + 2;
        }

        while (!nodes.empty()) {
            depth += 1;
            vector<int> newNodes;
            for (int node1 : nodes) {
                int loReverseStart = max(node1 - step, 0);
                int hiReverseStart = min(node1, n - k);
                int loNode2 = 2 * loReverseStart + k - 1 - node1;
                int hiNode2 = 2 * hiReverseStart + k - 1 - node1;
                int postHiNode2 = hiNode2 + 2;
                int node2 = loNode2;
                while (node2 <= hiNode2) {
                    int nextNode2 = nextNode2s[node2];
                    nextNode2s[node2] = postHiNode2;
                    if (node2 >= 0 && node2 < n && out[node2] == -1) {
                        newNodes.push_back(node2);
                        out[node2] = depth;
                    }
                    node2 = nextNode2;
                }
            }
            nodes = newNodes;
        }

        for (int i = 0; i < n; ++i) {
            if (out[i] == -2) {
                out[i] = -1;
            }
        }
        return out;
    }
};
