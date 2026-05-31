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

class Codec {
    TreeNode* constructBT(string& s, size_t &pos) {
        size_t delimit = pos + 1;
        while (delimit < s.size() && s[delimit] != ',') ++delimit;
        string subs = s.substr(pos, delimit - pos);
        TreeNode *t = nullptr;
        if (delimit < s.size())
            pos = delimit + 1;
        else pos = s.size();

        if (subs == "#") {
            return nullptr;
        }
        t = new TreeNode(stoi(subs));
        if (pos < s.size())
            t->left = constructBT(s, pos);
        if (pos < s.size())
            t->right = constructBT(s, pos);
        return t;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if (!root) return "#,";
       string s = to_string(root->val) + ",";
       s += serialize(root->left);
       s += serialize(root->right);
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t t = 0;
        return constructBT(data, t);
    }
};
