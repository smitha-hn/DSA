
class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {
        
    }

    bool insert(int val) {
        bool notPresent = mp[val].empty();

        nums.push_back(val);
        mp[val].insert(nums.size() - 1);

        return notPresent;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end() || mp[val].empty()) {
            return false;
        }

        int index = *mp[val].begin();
        int last = nums.back();

        mp[val].erase(index);

        if (index != nums.size() - 1) {
            nums[index] = last;

            mp[last].erase(nums.size() - 1);
            mp[last].insert(index);
        }

        nums.pop_back();

        if (mp[val].empty()) {
            mp.erase(val);
        }

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
