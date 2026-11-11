
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        vector<int> remaining;

        for (int num : arr2) {
            for (int x : arr1) {
                if (x == num) {
                    result.push_back(x);
                }
            }
        }

        for (int x : arr1) {
            bool found = false;

            for (int num : arr2) {
                if (x == num) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                remaining.push_back(x);
            }
        }

        sort(remaining.begin(), remaining.end());

        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};

