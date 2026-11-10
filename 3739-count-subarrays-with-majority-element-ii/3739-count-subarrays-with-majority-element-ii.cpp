
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> bit(2 * n + 5, 0);

        auto update = [&](int i) {
            while (i < bit.size()) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        };

        int prefix = 0;
        long long ans = 0;

        update(n + 1);

        for (int x : nums) {
            prefix += (x == target ? 1 : -1);

            // Count previous prefix sums smaller than current
            ans += query(prefix + n);

            update(prefix + n + 1);
        }

        return ans;
    }
};
