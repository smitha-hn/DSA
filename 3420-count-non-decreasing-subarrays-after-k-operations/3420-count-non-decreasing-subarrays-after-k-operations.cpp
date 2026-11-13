class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;

        while ((1LL << LOG) <= n)
            LOG++;

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Find next greater element
        vector<int> nxt(n + 1, n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nxt[i] = st.back();

            st.push_back(i);
        }

        // Binary lifting tables
        vector<vector<int>> jump(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> cost(LOG,
                                      vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            jump[0][i] = nxt[i];

            cost[0][i] =
                1LL * nums[i] * (nxt[i] - i)
                - (pref[nxt[i]] - pref[i]);
        }

        for (int p = 1; p < LOG; p++) {
            for (int i = 0; i < n; i++) {
                int mid = jump[p - 1][i];

                jump[p][i] = jump[p - 1][mid];

                cost[p][i] =
                    cost[p - 1][i] + cost[p - 1][mid];
            }
        }

        // Calculate operations needed for [l, r]
        auto getCost = [&](int l, int r) -> long long {
            long long res = 0;
            int cur = l;

            for (int p = LOG - 1; p >= 0; p--) {
                if (jump[p][cur] <= r) {
                    res += cost[p][cur];
                    cur = jump[p][cur];
                }
            }

            res += 1LL * nums[cur] * (r - cur + 1)
                   - (pref[r + 1] - pref[cur]);

            return res;
        };

        // Sliding window
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (left <= right && getCost(left, right) > k) {
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};

