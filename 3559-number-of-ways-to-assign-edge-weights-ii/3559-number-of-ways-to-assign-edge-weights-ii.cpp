
class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                 vector<vector<int>>& queries) {

        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 20;

        vector<vector<int>> up(n + 1, vector<int>(LOG));
        vector<int> depth(n + 1, 0);

        // BFS to calculate depth and ancestors
        queue<int> q;
        q.push(1);

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                if (!visited[child]) {
                    visited[child] = true;
                    depth[child] = depth[node] + 1;
                    up[child][0] = node;

                    for (int j = 1; j < LOG; j++) {
                        up[child][j] =
                            up[up[child][j - 1]][j - 1];
                    }

                    q.push(child);
                }
            }
        }

        // LCA function
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[u][j];
            }

            if (u == v)
                return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };

        // Fast power
        auto power = [&](int exp) {
            long long res = 1, base = 2;

            while (exp > 0) {
                if (exp & 1)
                    res = res * base % MOD;

                base = base * base % MOD;
                exp >>= 1;
            }

            return (int)res;
        };

        vector<int> answer;

        for (auto &query : queries) {
            int u = query[0];
            int v = query[1];

            int p = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[p];

            if (dist == 0)
                answer.push_back(0);
            else
                answer.push_back(power(dist - 1));
        }

        return answer;
    }
};
