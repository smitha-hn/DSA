
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Calculate maximum twin sum
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            int sum = first->val + second->val;
            maxSum = max(maxSum, sum);

            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
