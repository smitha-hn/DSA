
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        // Store frequencies in a vector
        vector<int> v;
        for (auto x : freq) {
            v.push_back(x.second);
        }

        // Sort frequencies in ascending order
        sort(v.begin(), v.end());

        // Remove numbers with the smallest frequencies
        int unique = v.size();

        for (int i = 0; i < v.size(); i++) {
            if (k >= v[i]) {
                k -= v[i];
                unique--;
            } else {
                break;
            }
        }

        return unique;
    }
};