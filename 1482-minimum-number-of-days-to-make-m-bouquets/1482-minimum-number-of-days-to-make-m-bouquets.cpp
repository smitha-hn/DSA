class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        auto possible = [&](int days) {
            int bouquets = 0;
            int flowers = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= days) {
                    flowers++;

                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            return bouquets >= m;
        };

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};