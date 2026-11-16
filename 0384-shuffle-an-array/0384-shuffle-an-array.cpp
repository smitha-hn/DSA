
class Solution {
private:
    vector<int> original;
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        original = nums;
        this->nums = nums;
    }

    vector<int> reset() {
        nums = original;
        return nums;
    }

    vector<int> shuffle() {
        nums = original;

        for (int i = nums.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);

            swap(nums[i], nums[j]);
        }

        return nums;
    }
};
