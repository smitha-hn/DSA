
class Solution {
public:
    int mergeSort(vector<long long>& prefix, int left, int right,
                  int lower, int upper) {
        
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int count = mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);

        int j = mid + 1, k = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (k <= right && prefix[k] - prefix[i] < lower)
                k++;

            while (j <= right && prefix[j] - prefix[i] <= upper)
                j++;

            count += j - k;
        }

        vector<long long> temp;
        int i = left, p = mid + 1;

        while (i <= mid && p <= right) {
            if (prefix[i] <= prefix[p])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[p++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (p <= right)
            temp.push_back(prefix[p++]);

        for (int i = left; i <= right; i++)
            prefix[i] = temp[i - left];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, n, lower, upper);
    }
};
