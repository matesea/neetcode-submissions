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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (q.size() > 0) {
            int sz = q.size();
            vector<int> v;
            while (sz-- > 0) {
                TreeNode *f = q.front();
                q.pop();
                v.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            res.push_back(v);
            level++;
        }
        return res;
    }
};
