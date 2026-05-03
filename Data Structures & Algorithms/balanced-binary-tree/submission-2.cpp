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
    unordered_map<TreeNode*, int> um;
    int height(TreeNode *root) {
        if (!root) return 0;
        if (um.find(root) != um.end())
            return um[root];
        return um[root] = 1 + max(height(root->left), height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = height(root->left),
            right = height(root->right);
        if (left + 1 < right || left > right + 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};
