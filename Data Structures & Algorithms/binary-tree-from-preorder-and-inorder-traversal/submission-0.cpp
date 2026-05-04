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
    unordered_map<int,int> idx;
    TreeNode *rec(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pl > pr) return nullptr;
        if (pl == pr) return new TreeNode(preorder[pl]);
        int ii = idx[preorder[pl]];
        int left = ii - il, right = ir - ii;
        TreeNode *res = new TreeNode(preorder[pl]);
        res->left = rec(preorder, pl+1, pl + left, inorder, il, ii - 1);
        res->right = rec(preorder, pl + left + 1, pr, inorder, ii + 1, ir);
        return res;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < inorder.size(); ++i) {
            idx[inorder[i]] = i;
        }
        return rec(preorder, 0, n - 1, inorder, 0, n-1);
    }
};
