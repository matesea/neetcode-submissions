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
    int res = -1000;
    int rec(TreeNode *root) {
        if (!root) return 0;
        int left = rec(root->left);
        int right = rec(root->right);
        res = max(res, root->val + max(left, 0) + max(right, 0));
        return root->val + max(max(left, right), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        rec(root);
        return res;
    }
};
