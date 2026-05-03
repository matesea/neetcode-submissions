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
    bool sameTree(TreeNode* p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p && q || p && !q || p->val != q->val)
            return false;
        if (!sameTree(p->left, q->left) || !sameTree(p->right, q->right))
            return false;
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (root->val == subRoot->val && sameTree(root, subRoot))
            return true;
        if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
            return true;
        return false;
    }
};
