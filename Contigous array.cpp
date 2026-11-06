
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        mp[0] = -1;

        int count = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                count--;
            else
                count++;

            if (mp.find(count) != mp.end()) {
                maxLen = max(maxLen, i - mp[count]);
            }
            else {
                mp[count] = i;
            }
        }

        return maxLen;
    }
};
