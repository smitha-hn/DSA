class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        Node* leftmost = root;

        while (leftmost->left != NULL) {
            Node* curr = leftmost;

            while (curr != NULL) {
                curr->left->next = curr->right;

                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};