
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        unordered_map<int, int> last;
        int left = 0;
        int ans = 2;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            // Find distinct prime factors
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {

                    if (last.count(p)) {
                        left = max(left, last[p] + 1);
                    }

                    last[p] = i;

                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }

            // Remaining prime factor
            if (x > 1) {
                if (last.count(x)) {
                    left = max(left, last[x] + 1);
                }

                last[x] = i;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};

 