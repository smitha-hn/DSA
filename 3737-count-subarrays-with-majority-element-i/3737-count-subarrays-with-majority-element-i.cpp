
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        long long ans = 0;
        int prefix = 0;

        unordered_map<int, long long> freq;
        freq[0] = 1;

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            for (auto it = freq.begin(); it != freq.end(); it++) {
                if (it->first < prefix) {
                    ans += it->second;
                }
            }

            freq[prefix]++;
        }

        return ans;
    }
};
