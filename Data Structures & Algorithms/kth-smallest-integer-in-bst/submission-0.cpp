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
    vector<int> v;
    void help(TreeNode *root, int k) {
        if (!root || v.size() >= k)
            return;
        help(root->left, k);
        if (v.size() >= k) return;
        v.push_back(root->val);
        if (v.size() >= k) return;
        help(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       help(root, k); 
       return v.back();
    }
};
