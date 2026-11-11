class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long option1 = 1LL * cost1 * need1
                         + 1LL * cost2 * need2;

        int mn = min(need1, need2);
        int mx = max(need1, need2);

        long long option2 = 1LL * costBoth * mn
                          + 1LL * cost1 * (need1 - mn)
                          + 1LL * cost2 * (need2 - mn);

        long long option3 = 1LL * costBoth * mx;

        return min({option1, option2, option3});
    }
};
