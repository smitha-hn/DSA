
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
            return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        prev->next = nullptr;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
