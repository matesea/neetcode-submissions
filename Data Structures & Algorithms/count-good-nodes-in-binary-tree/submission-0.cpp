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
    int res;
    void help(TreeNode *root, int m) {
        if (!root) return;
        if (root->val >= m)
            res++;
        help(root->left, max(m, root->val));
        help(root->right, max(m, root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        res = 0;
        help(root, INT_MIN);
        return res;
    }
};
