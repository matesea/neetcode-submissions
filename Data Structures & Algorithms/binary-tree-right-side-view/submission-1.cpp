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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> res; 
       if (!root) return res;
       queue<TreeNode *> q;
       q.push(root);
       while (q.size() > 0) {
        int val = 0;
        for (int sz = q.size(); sz > 0; --sz) {
            TreeNode *t = q.front();
            q.pop();
            val = t->val;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        res.push_back(val);
       }
       return res;
    }
};
