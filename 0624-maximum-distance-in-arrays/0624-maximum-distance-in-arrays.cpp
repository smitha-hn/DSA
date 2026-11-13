
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();

        int ans = 0;

        for (int i = 1; i < arrays.size(); i++) {

            int currMin = arrays[i][0];
            int currMax = arrays[i].back();

            ans = max(ans, max(abs(currMax - minVal),
                               abs(maxVal - currMin)));

            minVal = min(minVal, currMin);
            maxVal = max(maxVal, currMax);
        }

        return ans;
    }
};
