class Solution {
private:
    bool valid(TreeNode* node, long long left, long long right) {
        if (!node) {
            return true;
        }

        if (!(node->val > left && node->val < right)) {
            return false;
        }

        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};