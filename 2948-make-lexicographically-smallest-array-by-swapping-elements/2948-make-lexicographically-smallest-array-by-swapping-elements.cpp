
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            vector<int> values;
            vector<int> indices;

            values.push_back(arr[i].first);
            indices.push_back(arr[i].second);

            int j = i + 1;

            while (j < n && arr[j].first - arr[j - 1].first <= limit) {
                values.push_back(arr[j].first);
                indices.push_back(arr[j].second);
                j++;
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j;
        }

        return ans;
    }
};
