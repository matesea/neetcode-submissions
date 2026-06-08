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
    void _inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        _inorder(root->left, res);
        res.push_back(root->val);
        _inorder(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res; 
       _inorder(root, res);
       return res;
    }
};