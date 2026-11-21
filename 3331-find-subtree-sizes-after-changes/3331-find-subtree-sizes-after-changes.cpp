
class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;

    void dfs(int node, vector<int>& parent, string& s,
             vector<int>& last) {

        int c = s[node] - 'a';
        int old = last[c];

        if (node != 0) {
            parent[node] = (old == -1) ? parent[node] : old;
        }

        last[c] = node;

        for (int child : adj[node]) {
            dfs(child, parent, s, last);
        }

        last[c] = old;
    }

    int calc(int node, vector<vector<int>>& tree) {
        int size = 1;

        for (int child : tree[node]) {
            size += calc(child, tree);
        }

        answer[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        answer.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent = parent;

        dfs(0, newParent, s, last);

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        calc(0, tree);

        return answer;
    }
};
