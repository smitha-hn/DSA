
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // If the list has only one node
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Find the middle node
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;

        return head;
    }
};
