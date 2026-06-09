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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (root->left) {
            TreeNode *prev = root;
            TreeNode *current = root->left;
            while (current->right) {
                prev = current;
                current = current->right;
            }
            if (prev != root)
                prev->right = current->left;
            else
                prev->left = current->left;
            root->val = current->val;
            return root;
        }
        if (root->right) {
            TreeNode *prev = root;
            TreeNode *current = root->right;
            while (current->left) {
                prev = current;
                current = current->left;
            }
            if (prev != root)
                prev->left = current->right;
            else prev->right = current->right;
            root->val = current->val;
            return root;
        }
    }
};