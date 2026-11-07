
class Solution {
public:
    int MOD = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;

        queue<pair<int,int>> q;
        q.push({1, 0});

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int next : adj[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, depth + 1});
                }
            }
        }

        long long ans = 1;
        long long base = 2;
        int exp = maxDepth - 1;

        // Calculate 2^(maxDepth - 1)
        while (exp > 0) {
            if (exp % 2 == 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }
};
