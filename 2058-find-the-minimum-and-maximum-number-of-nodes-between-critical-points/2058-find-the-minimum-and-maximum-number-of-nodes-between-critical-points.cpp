
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;

        int index = 0;

        ListNode* curr = head;

        while (curr->next != nullptr && curr->next->next != nullptr) {
            int a = curr->val;
            int b = curr->next->val;
            int c = curr->next->next->val;

            if ((b > a && b > c) || (b < a && b < c)) {
                if (first == -1) {
                    first = index + 1;
                }

                if (prev != -1) {
                    minDist = min(minDist, index + 1 - prev);
                }

                prev = index + 1;
            }

            curr = curr->next;
            index++;
        }

        if (first == -1 || first == prev) {
            return ans;
        }

        ans[0] = minDist;
        ans[1] = prev - first;

        return ans;
    }
};
