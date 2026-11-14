
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<long long> st;
        long long ans = LLONG_MAX;

        for (int i = l; i <= n; i++) {

            // Add valid starting prefix
            st.insert(prefix[i - l]);

            // Remove prefixes outside allowed range
            int idx = i - r - 1;

            if (idx >= 0) {
                auto it = st.find(prefix[idx]);
                if (it != st.end()) {
                    st.erase(it);
                }
            }

            // Find smallest positive subarray sum
            auto it = st.lower_bound(prefix[i]);

            if (it != st.begin()) {
                --it;
                ans = min(ans, prefix[i] - *it);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
