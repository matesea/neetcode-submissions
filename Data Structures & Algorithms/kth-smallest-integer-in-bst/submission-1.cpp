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
    void help(TreeNode *root, int& k, int& res) {
        if (!root || k <= 0)
            return;
        help(root->left, k, res);
        if (k <= 0) return;
        k--;
        if (k == 0) res = root->val;
        if (k <= 0) return;
        help(root->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
       help(root, k, res); 
       return res;
    }
};
