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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode *rec(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preIdx >= preorder.size())
            return nullptr;
        if (limit == inorder[inIdx]) {
            return nullptr;
        }
        TreeNode *res = new TreeNode(preorder[preIdx++]);
        res->left = rec(preorder, inorder, res->val);
        inIdx++;
        res->right = rec(preorder, inorder, limit);
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder, inorder, INT_MAX);
    }
};
