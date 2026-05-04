/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool help(TreeNode *root, int mi, int mx) {
        if (!root) return true;
        if (root->val <= mi || root->val >= mx)
            return false;
        return help(root->left, mi, min(mx, root->val)) && help(root->right, max(mi, root->val), mx);
    }
public:
    bool isValidBST(TreeNode* root) {
        return help(root, INT_MIN, INT_MAX);
    }
};
