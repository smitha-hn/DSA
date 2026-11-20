class Solution {
public:
    int maxi = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        maxi = max(maxi, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};