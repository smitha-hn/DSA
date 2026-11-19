
class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        int value = node->val;

        if (node->right != nullptr) {
            pushLeft(node->right);
        }

        return value;
    }

    bool hasNext() {
        return !st.empty();
    }
};
